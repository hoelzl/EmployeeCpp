//
// Created by tc on 2019-06-05.
//

#ifndef EMPLOYEE_TIME_H
#define EMPLOYEE_TIME_H

#include <ctime>

class Time
{
public:
    explicit Time(const std::tm& time);

    std::tm GetTime() const;

    bool operator==(const Time& rhs) const;

    bool operator<(const Time& rhs) const;

private:
    std::tm time_;
};

#endif // EMPLOYEE_TIME_H
