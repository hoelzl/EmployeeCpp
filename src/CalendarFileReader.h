//
// Created by tc on 2019-06-05.
//

#ifndef EMPLOYEE_CALENDARFILEREADER_H
#define EMPLOYEE_CALENDARFILEREADER_H

#include "CalendarReader.h"

class CalendarFileReader : public CalendarReader
{
public:
    explicit CalendarFileReader(const char* calendar_file_name);

private:
    std::map<Time, Location> ReadCalenderData(int employee_id) const override;

private:
    const char* calender_file_name_;
};

#endif // EMPLOYEE_CALENDARFILEREADER_H
