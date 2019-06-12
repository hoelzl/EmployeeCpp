//
// Created by Matthias Hölzl on 2019-06-07.
//

#include "EmployeeFactory.h"
#include <fstream>
#include <iomanip>

EmployeeFactory::EmployeeFactory(const char* data_file_name) : data_file_name_(data_file_name)
{
}

EmployeeData EmployeeFactory::readEmployeeData(int id) const
{
    EmployeeData result{id};

    std::ifstream data{data_file_name_};
    while (data)
    {
        std::string first_name, last_name;
        data >> result.id_ >> result.first_name_ >> result.last_name_ >>
            std::get_time(&result.birthday_, "%Y-%m-%d");
        if (result.id_ >= 0 && result.id_ == id)
        {
            break;
        }
    }

    return result;
}
Employee EmployeeFactory::CreateEmployee(int id)
{
    EmployeeData data{readEmployeeData(id)};
    return Employee(id, Name{data.first_name_, data.last_name_}, data.birthday_);
}
