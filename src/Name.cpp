#include <utility>

#include <utility>

//
// Created by tc on 2019-06-05.
//

#include "Name.h"
#include <ctime>
#include <fstream>

Name::Name(std::string first_name, std::string last_name)
    : first_name_{std::move(first_name)}, last_name_{std::move(last_name)}
{
}

std::ostream& operator<<(std::ostream& stream, const Name& name)
{
    stream << name.first_name_ << " " << name.last_name_;
    return stream;
}
