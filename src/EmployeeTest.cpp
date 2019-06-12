#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

// Created by Matthias Hölzl on 2019-05-28.
//
#include "Employee.h"
#include "gmock/gmock.h"
#include <sstream>

using namespace ::testing;

// It's basically impossible to write a unit test for this version of the program since it provides
// no seams that allow us to intercept the file system access during construction.
TEST(Employee, CreateEmployee)
{
    Employee unit{7};
    std::ostringstream stream{};
    const std::string expected{"Employee{7: Rogers Nelson, 1958-06-07, $100}\n"};

    stream << unit;
    ASSERT_THAT(stream.str(), Eq(expected));
}

#pragma clang diagnostic pop
