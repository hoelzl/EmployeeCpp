//
// Created by tc on 2019-06-05.
//

#ifndef EMPLOYEE_APPOINTMENTPROVIDER_H
#define EMPLOYEE_APPOINTMENTPROVIDER_H

#include "Location.h"
#include "Time.h"
#include <map>

class AppointmentProvider
{
public:
    virtual std::map<Time, Location> ProvideAppointments(int employee_id) const = 0;
};

#endif // EMPLOYEE_APPOINTMENTPROVIDER_H
