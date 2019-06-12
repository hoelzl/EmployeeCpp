//
// Created by Dr. Matthias Hölzl (tc) on 2019-06-05.
//

#include "Calendar.h"
#include <fstream>
#include <iomanip>
#include <iostream>

Calendar::Calendar(int employee_id) : employee_id_{employee_id}, appointments_{}
{
    std::ifstream data{"employee-calendars.txt"};
    while (data)
    {
        int data_id{-1};
        std::tm date{};
        int building{-1};
        data >> data_id >> std::get_time(&date, "%Y-%m-%d/%H:%M") >> building;
        if (data_id == employee_id)
        {
            AddAppointment(date, Location{building});
        }
    }
}

bool Calendar::HasAppointmentAt(std::tm time, Location& location)
{
    const Time& calender_time = Time{time};
    return appointments_.find(calender_time) != appointments_.cend();
}

void Calendar::AddAppointment(std::tm time, const Location& location)
{
    appointments_[Time{time}] = location;
}

Calendar::Time::Time(const tm& time) : time_(time)
{
}

bool Calendar::Time::operator==(const Calendar::Time& rhs) const
{
    return time_.tm_year == rhs.time_.tm_year && time_.tm_mon == rhs.time_.tm_mon &&
           time_.tm_mday == rhs.time_.tm_mday && time_.tm_hour == rhs.time_.tm_hour;
}

std::tm Calendar::Time::GetTime() const
{
    return time_;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"
bool Calendar::Time::operator<(const Calendar::Time& rhs) const
{
    if (time_.tm_year < rhs.time_.tm_year)
    {
        return true;
    }
    if (time_.tm_year > rhs.time_.tm_year)
    {
        return false;
    }
    if (time_.tm_mon < rhs.time_.tm_mon)
    {
        return true;
    }
    if (time_.tm_mon > rhs.time_.tm_mon)
    {
        return false;
    }
    if (time_.tm_mday < rhs.time_.tm_mday)
    {
        return true;
    }
    if (time_.tm_mday > rhs.time_.tm_mday)
    {
        return false;
    }
    if (time_.tm_hour < rhs.time_.tm_hour)
    {
        return true;
    }
    if (time_.tm_hour > rhs.time_.tm_hour)
    {
        return false;
    }
    return true;
}
#pragma clang diagnostic pop

std::ostream& operator<<(std::ostream& stream, const Calendar& calendar)
{
    for (auto pair : calendar.appointments_)
    {
        const tm& appointment_time = pair.first.GetTime();
        std::cout << "Appointment at " << std::put_time(&appointment_time, "%Y-%m-%d %H:%M") << ", "
                  << pair.second << std::endl;
    }
    return stream;
}
