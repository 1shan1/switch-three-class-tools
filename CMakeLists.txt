cmake_minimum_required(VERSION 3.9)
project(caffe_crowd_test_video)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/include)

set(CAFFE_ROOT ${CMAKE_SOURCE_DIR}/3rdparty/caffe)
include_directories(${CAFFE_ROOT}/include)
link_directories(${CAFFE_ROOT}/lib)

## cuda
##include_directories(APPEND PERSON_INCLUDE_DIRS PUBLIC /usr/local/cuda/include)
##link_directories(APPEND PERSON_LINKER_LIBS PUBLIC /usr/local/cuda/lib64/)
include_directories(/usr/local/cuda/include)
link_directories(/usr/local/cuda/lib64/)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/cudnn)

#include_directories(/usr/local/include)
#include_directories(/usr/local/cuda/include)

##
#link_directories(/usr/local/lib)
#link_directories(/usr/local/cuda/lib64)

#link_directories(/usr/local/ssl/lib)
#link_directories(/usr/lib/x86_64-linux-gnu/hdf5/serial)
#link_directories(/usr/lib/)
#link_directories(/lib/x86_64-linux-gnu/)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)
add_executable(caffe_crowd_test_video main.cpp CrowdEstimate.cpp)

target_link_libraries(caffe_crowd_test_video opencv_core opencv_imgproc opencv_highgui opencv_ml opencv_video opencv_features2d opencv_calib3d opencv_objdetect opencv_imgcodecs opencv_videoio
        opencv_flann boost_serialization boost_system boost_filesystem glog caffe boost_thread protobuf atlas cublas cudart culibos curand cudnn
        ssl3 pthread dl rt)