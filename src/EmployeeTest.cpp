#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
// Created by Matthias Hölzl on 2019-05-28.
//

#include "Employee.h"
#include "EmployeeFactory.h"
#include "FileAppointmentProvider.h"
#include "gmock/gmock.h"

using namespace ::testing;

TEST(Employee, CreateEmployee)
{
    const Name name = Name{"Rogers", "Nelson"};
    const tm birthday = std::tm{0, 0, 0, 7, 5 /* tm_mon goes from 0 to 11 */, 58, 0, 0, 0};
    const Employee unit{7, name, birthday};

    ASSERT_THAT(unit.GetId(), Eq(7));
    ASSERT_THAT(unit.GetName(), Eq(name));
    ASSERT_THAT(unit.IsBirthday(Time(birthday)), Eq(true));
}

#pragma clang diagnostic pop
