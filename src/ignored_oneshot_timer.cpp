/**
* Copyright (C) 2014, BMW Car IT GmbH
* Author: Jonas Sticha (Jonas.Sticha@bmw-carit.de)
*
* This software is licensed under BSD 3-clause License
* (see http://spdx.org/licenses/BSD-3-Clause).
**/

#include "ros/ros.h"
#include <time.h>
#include <iostream>

struct timespec sleepTimeout;
bool callbackCalled = false;

void timerCallback(const ros::TimerEvent& te)
{
	callbackCalled = true;
}

void blockUntilCallbackCalled()
{
	std::cout << ": WAIT...";
	std::cout.flush();
	for(int i = 0; true; i++)
	{
		nanosleep((const struct timespec*) &sleepTimeout, NULL);
		if(callbackCalled)
		{
			break;
		}
		if(i == 300)
		{
			std::cout << "...not firing?";
			std::cout.flush();
		}
	}
	std::cout << "...DONE" << std::endl;
}

int main(int argc, char* argv[])
{
	sleepTimeout.tv_sec = 0;
	sleepTimeout.tv_nsec = 1300000; // 1.3 milliseconds
	ros::init(argc, argv, "ignored_oneshot_timer");
	ros::NodeHandle nodeHandle;
	ros::AsyncSpinner spinner(0);
	spinner.start();
	callbackCalled = false;
	ros::Timer rosTimer = nodeHandle.createTimer(ros::Duration(0.01), &timerCallback, true);
	blockUntilCallbackCalled();
	//Repeatedly set oneshot timer and wait until it fires
	for(int i = 0; true; i++)
	{
		std::cout << "LOOP" << i;
		callbackCalled = false;
		rosTimer.setPeriod(ros::Duration(0.001)); //1 millisecond
		rosTimer.start();
		blockUntilCallbackCalled();
	}
}
