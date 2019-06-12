//
// Created by Dr. Matthias Hölzl (tc) on 2019-06-05.
//

#include "Calendar.h"
#include <fstream>
#include <iomanip>
#include <iostream>

Calendar::Calendar(int employee_id, const CalendarReader& calendar_reader)
    : employee_id_{employee_id}, appointments_{}
{
    appointments_ = calendar_reader.ReadCalenderData(employee_id);
}

bool Calendar::HasAppointmentAt(std::tm time, Location& location)
{
    const Time& calender_time = Time{time};
    return appointments_.find(calender_time) != appointments_.cend();
}

void Calendar::AddAppointment(std::tm time, const Location& location)
{
    appointments_.emplace(std::make_pair(Time{time}, location));
}

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
