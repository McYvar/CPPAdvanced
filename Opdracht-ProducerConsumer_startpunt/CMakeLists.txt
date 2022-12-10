cmake_minimum_required(VERSION 3.8)
project(Opdracht-ProducerConsumer)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
	main.cpp
)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(Opdracht-ProducerConsumer ${SOURCE_FILES})
