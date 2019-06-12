#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
// Created by Matthias Hölzl on 2019-05-28.
//

#include "Employee.h"
#include "EmployeeFactory.h"
#include "FileAppointmentProvider.h"
#include "gmock/gmock.h"

TEST(Employee, CreateEmployee)
{
    EmployeeFactory employee_factory{"employee-data.txt"};

    Employee employee{employee_factory.CreateEmployee(1)};
    ASSERT_TRUE(true);
}

#pragma clang diagnostic pop
