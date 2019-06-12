//
// Created by tc on 2019-06-05.
//

#include "Name.h"
#include <ctime>
#include <fstream>

Name::Name(int id, const NameReader& name_reader)
    : first_name_{"<no given name>"}, last_name_{"<no last name>"}
{
    NameData name_data{name_reader.readName(id)};
    first_name_ = name_data.first_name_;
    last_name_ = name_data.last_name_;
}

std::ostream& operator<<(std::ostream& stream, const Name& name)
{
    stream << name.first_name_ << " " << name.last_name_;
    return stream;
}
