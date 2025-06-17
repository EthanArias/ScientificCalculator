#pragma once
#include <iostream>
// Class calculator 
class Calculator
{
public:

    // Function to take input
    // from user
    void result()
    {
        std::cout << "Enter First Number: ";
        std::cin >> a;
        std::cout << "Enter Second Number: ";
        std::cin >> b;
    }

    // Function to add two numbers
    float add()
    {
        return a + b;
    }

    // Function to subtract two numbers
    float sub()
    {
        return a - b;
    }

    // Function to multiply two numbers
    float mul()
    {
        return a * b;
    }

    // Function to divide two numbers
    float div()
    {
        if (b == 0)
        {
            std::cout << "Division By Zero" << std::endl;
            return INFINITY;
        }
        else
        {
            return a / b;
        }
    }
private:
    float a, b;
};
