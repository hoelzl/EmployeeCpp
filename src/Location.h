//
// Created by Dr. Matthias Hölzl (tc) on 2019-06-05.
//

#ifndef EMPLOYEE_LOCATION_H
#define EMPLOYEE_LOCATION_H

#include <ostream>
class Location
{
private:
public:
    Location();

    explicit Location(int building_number);

private:
    friend bool operator==(Location lhs, Location rhs);
    friend std::ostream& operator<<(std::ostream& stream, const Location& location);
    int building_number_{-1};
};

bool operator==(Location lhs, Location rhs);

std::ostream& operator<<(std::ostream& stream, const Location& location);

#endif // EMPLOYEE_LOCATION_H
