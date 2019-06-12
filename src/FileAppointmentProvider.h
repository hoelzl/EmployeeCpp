//
// Created by tc on 2019-06-05.
//

#ifndef EMPLOYEE_FILEAPPOINTMENTPROVIDER_H
#define EMPLOYEE_FILEAPPOINTMENTPROVIDER_H

#include "AppointmentProvider.h"

class FileAppointmentProvider : public AppointmentProvider
{
public:
    explicit FileAppointmentProvider(const char* calendar_file_name);

private:
    std::map<Time, Location> ProvideAppointments(int employee_id) const override;

private:
    const char* calender_file_name_;
};

#endif // EMPLOYEE_FILEAPPOINTMENTPROVIDER_H
