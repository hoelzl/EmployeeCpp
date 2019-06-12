#include "Employee.h"
#include "EmployeeFactory.h"
#include "FileAppointmentProvider.h"
#include <iostream>

int main()
{
    EmployeeFactory employee_factory{"employee-data.txt"};
    FileAppointmentProvider appointment_provider{"employee-calendars.txt"};

    std::cout << "Employee List\n\n";
    for (int i = 0; i < 5; ++i)
    {
        Employee employee{employee_factory.CreateEmployee(i)};
        employee.AddAppointments(appointment_provider);
        std::cout << i << ": " << employee << std::endl;
    }
    return 0;
}
