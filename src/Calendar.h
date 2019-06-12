//
// Created by Dr. Matthias Hölzl (tc) on 2019-06-05.
//

#ifndef EMPLOYEE_CALENDAR_H
#define EMPLOYEE_CALENDAR_H

#include "CalendarReader.h"
#include "Location.h"
#include "Time.h"
#include <ctime>
#include <map>

class Calendar
{
public:
    explicit Calendar(int employee_id, const CalendarReader& calendar_reader);
    
    bool HasAppointmentAt(std::tm time, Location& location);
    void AddAppointment(std::tm time, const Location& location);

private:
    friend std::ostream& operator<<(std::ostream& stream, const Calendar& calendar);
    int employee_id_;
    std::map<Time, Location> appointments_{};
};

std::ostream& operator<<(std::ostream& stream, const Calendar& calendar);

#endif // EMPLOYEE_CALENDAR_H
