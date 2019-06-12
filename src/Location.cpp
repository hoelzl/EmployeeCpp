//
// Created by Dr. Matthias Hölzl (tc) on 2019-06-05.
//

#include "Location.h"

Location::Location(int building_number) : building_number_(building_number)
{
}

Location::Location() : building_number_{-1}
{
}

bool operator==(Location lhs, Location rhs)
{
    if (lhs.building_number_ < 0 || rhs.building_number_ < 0)
    {
        return false;
    }
    return lhs.building_number_ == rhs.building_number_;
}
std::ostream& operator<<(std::ostream& stream, const Location& location)
{
    stream << "{Location: building " << location.building_number_ << "}";
    return stream;
}
