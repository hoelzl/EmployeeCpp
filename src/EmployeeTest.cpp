// Created by Matthias Hölzl on 2019-05-28.
//

#include "Employee.h"
#include "gmock/gmock.h"

TEST(Employee, CreateEmployee) // NOLINT(cert-err58-cpp)
{
    Employee employee{1};
    ASSERT_TRUE(true);
}

