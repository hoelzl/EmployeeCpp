//
// Created by tc on 2019-06-05.
//

#ifndef EMPLOYEE_EMPLOYEEDATAFILEREADER_H
#define EMPLOYEE_EMPLOYEEDATAFILEREADER_H

#include "EmployeeDataReader.h"

class EmployeeDataFileReader : public EmployeeDataReader
{
public:
    explicit EmployeeDataFileReader(const char* data_file_name);

private:
    EmployeeData readEmployeeData(int id) const override;

private:
    const char* data_file_name_;
};

#endif // EMPLOYEE_EMPLOYEEDATAFILEREADER_H
