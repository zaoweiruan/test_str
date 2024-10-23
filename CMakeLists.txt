cmake_minimum_required(VERSION 3.30)

project (test_str LANGUAGES CXX)
set(Boost_ROOT E:/vcpkg/installed/x64-mingw-dynamic/share)

set (package_name  unofficial-sqlite3)
#set(OPENSSL_ROOT  E:/vcpkg/installed/x64-mingw-dynamic/share)
#find_package(Boost CONFIG COMPONENTS asio program_options locale date_time PATHS E:/vcpkg/installed/x64-mingw-dynamic)
find_package(Boost CONFIG COMPONENTS asio program_options locale date_time)
find_package(${package_name} CONFIG REQUIRED PATHS E:/vcpkg/installed/x64-mingw-dynamic)

#find_package(unofficial-sqlite3 CONFIG REQUIRED PATHS E:/vcpkg/installed/x64-mingw-static)
set(CMAKE_BUILD_TYPE Debug) 
#set(CMAKE_BUILD_TYPE Release) 

#if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
#message("Setting build type to 'RelWithDebInfo' as none was specified.")
#set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
#set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
#endif()

#set(CMAKE_CONFIGURATION_TYPES "Release;Debug")


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(switch)
set_target_properties(switch PROPERTIES SOURCES  switch.cpp)

add_executable(test_str)
set_target_properties(test_str PROPERTIES SOURCES  test_str.cpp)

add_executable(boostdatetime)
set_target_properties(boostdatetime PROPERTIES SOURCES  boostdatetime.cpp)
target_link_libraries(boostdatetime Boost::date_time Boost::program_options Boost::locale )

add_executable(sqlite3_test)
set_target_properties(sqlite3_test PROPERTIES SOURCES  sqlite3_test.cpp)
target_link_libraries(sqlite3_test unofficial::sqlite3::sqlite3)

#
set (package_name  sqlite3_test)
#if (${package_name}_FOUND)
if (FALSE)

#get_target_property(libpath  unofficial::sqlite3::sqlite3 IMPORTED_LIBNAME)
#message(STATUS "libpath=${ibpath}")
#set (package_name  unofficial-sqlite3)
include (D:/mvnworkspace/findtargetproperty.cmake)
#set(AVAILABLE_CONFIGURATION_TYPES Debug)
#include (D:/mvnworkspace/findtargetproperty.cmake)
#get_available_configuration_types()
#get_cmake_property_list()
print_target_properties1(${package_name})
endif()
