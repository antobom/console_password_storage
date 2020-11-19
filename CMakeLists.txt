cmake_minimum_required(VERSION 3.10)

project(Password_storage_console)

include_directories("/opt/phc-winner-argon2/include")


file(GLOB src_files *.hpp *.cpp)
# HashParam.hpp HashParam.cpp HomePage.cpp HomePage.hpp
add_executable(${CMAKE_PROJECT_NAME} main.cpp ${src_files})

target_link_libraries(${CMAKE_PROJECT_NAME} argon2)