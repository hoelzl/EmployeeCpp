#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

// Created by Matthias Hölzl on 2019-05-28.
//

#include "Employee.h"
#include "CalendarFileReader.h"
#include "EmployeeDataFileReader.h"
#include "NameFileReader.h"
#include "gmock/gmock.h"

using namespace ::testing;

class EmployeeDataReaderStub : public EmployeeDataReader
{
public:
    EmployeeData readEmployeeData(int id) const override
    {
        return EmployeeData{7, std::tm{0, 0, 0, 7, 5 /* tm_mon goes from 0 to 11 */, 58, 0, 0, 0}};
    }
};

class NameReaderStub : public NameReader
{
public:
    NameData readName(int id) const override
    {
        return NameData{"Rogers", "Nelson"};
    }
};

class CalendarReaderStub : public CalendarReader
{
public:
    std::map<Time, Location> ReadCalenderData(int employee_id) const override
    {
        return std::map<Time, Location>{};
    }
};

TEST(Employee, CreateEmployee)
{
    EmployeeDataReaderStub employee_data_reader{};
    NameReaderStub name_reader{};
    CalendarReaderStub calendar_reader{};
    Employee employee{7, employee_data_reader, name_reader, calendar_reader};
    std::ostringstream stream{};
    const std::string result{"Employee{7: Rogers Nelson, 1958-06-07, $100}\n"};

    stream << employee;

    ASSERT_THAT(stream.str(), Eq(result));
}

#pragma clang diagnostic pop
