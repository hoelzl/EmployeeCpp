// Created by Matthias Hölzl on 2019-05-28.
//
#include "Employee.h"

#include <algorithm>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <utility>

Employee::Employee(int id, Name name, std::tm birthday)
    : id_{id}
    , name_{std::move(name)}
    , birthday_{birthday}
    , calendar_{std::make_unique<Calendar>(id)}
{
}

bool Employee::IsBirthday(Time time) const
{
    std::tm ctime = time.GetCTime();
    return (ctime.tm_mday == birthday_.tm_mday && ctime.tm_mon == birthday_.tm_mon);
}

double Employee::GetSalary() const
{
    double salary{100.0};
    if (name_.last_name_ == "Boss")
    {
        salary += 1000.0;
    }
    if (name_.first_name_.size() <= 3 || name_.last_name_.size() <= 3 ||
        name_.first_name_ == "Bill")
    {
        salary *= 1.1;
    }
    if (IsBirthday(Time(tm())))
    {
        salary += 150.0;
    }
    return salary;
}

void Employee::AddAppointments(const AppointmentProvider& appointment_provider)
{
    if (calendar_)
    {
        calendar_->AddAppointments(appointment_provider);
    }
}

bool Employee::IsAvailableForMeeting(const std::tm& time, const Location& location,
                                     bool blockIfAvailable)
{
    std::time_t current_time{std::time(nullptr)};
    std::tm right_now{*localtime(&current_time)};

    Location meeting_location{-1};
    if (calendar_->HasAppointmentAt(time, meeting_location))
    {
        return false;
    }
    if (blockIfAvailable)
    {
        calendar_->AddAppointment(time, location);
    }
    if (abs(time.tm_hour - right_now.tm_hour) <= 1)
    {
        return current_location_ == location;
    }
    return true;
}

std::ostream& operator<<(std::ostream& stream, const Employee& employee)
{
    stream << "Employee{" << employee.id_ << ": " << employee.name_ << ", "
           << std::put_time(&employee.birthday_, "%Y-%m-%d") << ", "
           << "$" << employee.GetSalary() << "}"
           << (employee.IsBirthday(Time::Now()) ? " *** It's their birthday!*** " : "")
           << std::endl;
    if (employee.calendar_)
    {
        stream << *employee.calendar_;
    }
    return stream;
}
