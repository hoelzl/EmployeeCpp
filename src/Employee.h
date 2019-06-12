// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include "Calendar.h"
#include "EmployeeDataReader.h"
#include "Location.h"
#include "Name.h"
#include <ctime>
#include <memory>
#include <ostream>

class Employee
{
public:
    Employee(int id, const EmployeeDataReader& employee_data_reader, const NameReader& name_reader,
             const CalendarReader& calendar_reader);

    // If `time` is right now, checks whether the employee is in location.
    // Otherwise checks the Employee's calendar whether they already have a meeting.
    bool IsAvailableForMeeting(const std::tm& time, const Location& location,
                               bool blockIfAvailable);

private:
    friend std::ostream& operator<<(std::ostream& stream, const Employee& employee);

    int id_;
    Name name_;
    std::tm birthday_;
    Location current_location_;
    std::unique_ptr<Calendar> calendar_;

    bool IsBirthday() const;
    double GetSalary() const;
};

std::ostream& operator<<(std::ostream& stream, const Employee& employee);

#endif // EMPLOYEE_EMPLOYEE_H
