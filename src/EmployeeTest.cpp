#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
// Created by Matthias Hölzl on 2019-05-28.
//

#include "Employee.h"
#include "CalendarFileReader.h"
#include "EmployeeDataFileReader.h"
#include "NameFileReader.h"
#include "gmock/gmock.h"

TEST(Employee, CreateEmployee)
{
    EmployeeDataFileReader employee_data_file_reader{"employee-data.txt"};
    NameFileReader name_file_reader{"employee-data.txt"};
    CalendarFileReader calendar_file_reader{"employee-calendars.txt"};

    Employee employee{1, employee_data_file_reader, name_file_reader, calendar_file_reader};
    ASSERT_TRUE(true);
}

#pragma clang diagnostic pop
