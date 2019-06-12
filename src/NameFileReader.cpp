//
// Created by tc on 2019-06-05.
//

#include "NameFileReader.h"
#include <ctime>
#include <fstream>
#include <iomanip>

NameFileReader::NameFileReader(const char* data_file_name) : data_file_name_(data_file_name)
{
}

NameData NameFileReader::readName(int id) const
{
    NameData result{};

    std::ifstream data_{data_file_name_};
    while (data_)
    {
        int data_id{-1};
        std::string first_name{"<missing name>"};
        std::string last_name{"<missing name>"};
        std::tm date{};
        data_ >> data_id >> first_name >> last_name >> std::get_time(&date, "%Y-%m-%d");
        if (data_id >= 0 && data_id == id)
        {
            result.first_name_ = first_name;
            result.last_name_ = last_name;
            break;
        }
    }
    return result;
}
