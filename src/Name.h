//
// Created by tc on 2019-06-05.
//

#ifndef EMPLOYEE_NAME_H
#define EMPLOYEE_NAME_H

#include "NameReader.h"
#include <iostream>

class Name
{
public:
    Name(int id, const NameReader& name_reader);

private:
    friend std::ostream& operator<<(std::ostream& Stream, const Name& Name);

    friend class Employee;

    std::string first_name_;
    std::string last_name_;
};

std::ostream& operator<<(std::ostream& stream, const Name& name);

#endif // EMPLOYEE_NAME_H
