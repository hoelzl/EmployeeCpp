#include "Employee.h"
#include <iostream>

constexpr int number_of_choices{3};

void PrintMenu()
{
    std::cout << "1) Print employee list\n";
    std::cout << "2) Set location\n";
    std::cout << "3) Exit program" << std::endl;
}

int GetUserChoice()
{
    int result{-1};
    while (result < 1 || result > number_of_choices)
    {
        std::cin >> result;
    }
    return result;
}

bool HandleUserChoice(int user_choice)
{
    switch (user_choice)
    {
    case 1:
    {
        Employee::PrintEmployeeList(5);
        break;
    }
    case 2:
    {
        int building_number{-1};
        std::cout << "Enter a building number: ";
        std::cin >> building_number;
        Location::user_location_ = Location{building_number};
        break;
    }
    case 3:
    {
        std::cout << "Exiting!" << std::endl;
        return true;
    }
    default:
    {
        std::cout << "Invalid user choice: " << user_choice << std::endl;
    }
    }
    return false;
}

int main()
{
    bool exit{false};
    do
    {
        PrintMenu();
        exit = HandleUserChoice(GetUserChoice());
    } while (!exit);
    return 0;
}
