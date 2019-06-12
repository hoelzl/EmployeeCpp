//
// Created by tc on 2019-06-05.
//

#include "EmployeeDataFileReader.h"
#include <fstream>
#include <iomanip>

EmployeeData EmployeeDataFileReader::readEmployeeData(int id) const
{
    EmployeeData result{id};

    std::ifstream data{data_file_name_};
    while (data)
    {
        std::string first_name{};
        std::string last_name{};
        data >> result.id_ >> first_name >> last_name >>
            std::get_time(&result.birthday_, "%Y-%m-%d");
        if (result.id_ >= 0 && result.id_ == id)
        {
            break;
        }
    }

    return result;
}

EmployeeDataFileReader::EmployeeDataFileReader(const char* data_file_name)
    : data_file_name_(data_file_name)
{
}
