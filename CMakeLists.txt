cmake_minimum_required(VERSION 3.10)
project(Employee)

set(CMAKE_CXX_STANDARD 17)

file(COPY employee-data.txt employee-calendars.txt DESTINATION .)

# Google Test
add_subdirectory(googletest)
enable_testing()
include_directories(googletest/googletest/include googletest/googlemock/include)

add_library(Employee
  src/Employee.cpp
  src/Employee.h
  src/Location.cpp
  src/Location.h
  src/Calendar.cpp
  src/Calendar.h
  )

add_executable(Main src/Main.cpp)
target_link_libraries(Main Employee)

add_executable(EmployeeTest src/EmployeeTest.cpp)
target_link_libraries(EmployeeTest Employee gtest gtest_main)
add_test(EmployeeTest EmployeeTest)
