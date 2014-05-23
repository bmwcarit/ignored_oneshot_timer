cmake_minimum_required(VERSION 2.8.3)
project(ignored_oneshot_timer)

find_package(catkin REQUIRED COMPONENTS roscpp)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ./src/${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})
install(TARGETS ${PROJECT_NAME}
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
