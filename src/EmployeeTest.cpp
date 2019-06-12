#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
// Created by Matthias Hölzl on 2019-05-28.
//

#include "Employee.h"
#include "gmock/gmock.h"

TEST(Employee, CreateEmployee)
{
    Employee employee{1};
    ASSERT_TRUE(true);
}

#pragma clang diagnostic pop
