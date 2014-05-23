## ignored_oneshot_timer ##

This repository contains a minimal program to investigate a surprising property of the ROS middleware.
It randomly gets stuck at one point in the blockUntilCallbackCalled() function, even though it theoretically shouldn't.
This means that a set oneshot timer just doesn't fire. This behaviour occurs randomly.
