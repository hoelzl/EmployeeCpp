//
// Created by tc on 2019-06-05.
//

#include "FileAppointmentProvider.h"
#include <fstream>
#include <iomanip>

FileAppointmentProvider::FileAppointmentProvider(const char* calendar_file_name)
    : calender_file_name_(calendar_file_name)
{
}

std::map<Time, Location> FileAppointmentProvider::ProvideAppointments(int employee_id) const
{
    std::map<Time, Location> result{};
    std::ifstream data{calender_file_name_};

    while (data)
    {
        int data_id{-1};
        std::tm date{};
        int building{-1};
        data >> data_id >> std::get_time(&date, "%Y-%m-%d/%H:%M") >> building;
        if (data_id == employee_id)
        {
            result[Time{date}] = Location{building};
        }
    }
    return result;
}
