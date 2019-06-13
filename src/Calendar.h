//
// Created by Dr. Matthias Hölzl (tc) on 2019-06-05.
//

#ifndef EMPLOYEE_CALENDAR_H
#define EMPLOYEE_CALENDAR_H

#include "Location.h"
#include <ctime>
#include <map>

class Calendar
{
public:
    class Time
    {
    public:
        explicit Time(const std::tm& time);

        std::tm GetTime() const;
        bool operator==(const Time& rhs) const;
        bool operator<(const Time& rhs) const;

    private:
        std::tm time_;
    };

    explicit Calendar(int employee_id);

    bool HasAppointmentAt(std::tm time, Location& location);
    void AddAppointment(std::tm time, const Location& location);

private:
    friend std::ostream& operator<<(std::ostream& stream, const Calendar& calendar);
    int employee_id_;
    std::map<Time, Location> appointments_{};
};

std::ostream& operator<<(std::ostream& stream, const Calendar& calendar);

#endif // EMPLOYEE_CALENDAR_H
