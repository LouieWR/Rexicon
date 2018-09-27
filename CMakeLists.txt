cmake_minimum_required(VERSION 2.6)
project(REXICON)

add_executable(rexicon
	src/testProj/main.cpp
)

add_library(rexicon 
src/test/Entity.cpp
)

target_link_libraries(testProj rexicon SDL2)