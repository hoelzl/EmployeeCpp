//
// Created by tc on 2019-06-05.
//

#include "Time.h"
#include <ctime>

Time::Time(const tm& time) : time_(time)
{
}

bool Time::operator==(const Time& rhs) const
{
    return time_.tm_year == rhs.time_.tm_year && time_.tm_mon == rhs.time_.tm_mon &&
           time_.tm_mday == rhs.time_.tm_mday && time_.tm_hour == rhs.time_.tm_hour;
}

std::tm Time::GetTime() const
{
    return time_;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"

bool Time::operator<(const Time& rhs) const
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
