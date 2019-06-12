#include "Employee.h"
#include <iostream>

int main()
{
    std::cout << "Employee List\n\n";
    for (int i = 0; i < 5; ++i)
    {
        Employee employee{i};
        std::cout << employee << std::endl;
    }
    return 0;
}
