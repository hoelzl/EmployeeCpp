//
// Created by tc on 2019-06-05.
//

#ifndef EMPLOYEE_EMPLOYEEDATAREADER_H
#define EMPLOYEE_EMPLOYEEDATAREADER_H

#include "Calendar.h"
#include "Location.h"
#include "Name.h"
#include <ctime>
#include <memory>

struct EmployeeData
{
    int id_;
    std::tm birthday_;
};

class EmployeeDataReader
{
public:
    virtual EmployeeData readEmployeeData(int id) const = 0;
};

#endif // EMPLOYEE_EMPLOYEEDATAREADER_H
