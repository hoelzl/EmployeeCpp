#include "CalendarFileReader.h"
#include "Employee.h"
#include "EmployeeDataFileReader.h"
#include "NameFileReader.h"
#include <iostream>

int main()
{
    EmployeeDataFileReader employee_data_file_reader{"employee-data.txt"};
    CalendarFileReader calendar_file_reader{"employee-calendars.txt"};
    NameFileReader name_file_reader{"employee-data.txt"};

    std::cout << "Employee List\n\n";
    for (int i = 0; i < 5; ++i)
    {
        Employee employee{i, employee_data_file_reader, name_file_reader, calendar_file_reader};
        std::cout << employee << std::endl;
    }
    return 0;
}
