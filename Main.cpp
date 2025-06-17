#include "Calculator.h"

int main() {
    int ch;
    Calculator c;
    std::cout << "Enter 1 to Add 2 Numbers" <<
        "\nEnter 2 to Subtract 2 Numbers" <<
        "\nEnter 3 to Multiply 2 Numbers" <<
        "\nEnter 4 to Divide 2 Numbers" <<
        "\nEnter 0 To Exit";

    do
    {
        std::cout << "\nEnter Choice: ";
        std::cin >> ch;
        switch (ch)
        {
        case 1:

            // result function invoked
            c.result();

            // add function to calculate sum
            std::cout << "Result: " <<
                c.add() << std::endl;
            break;
        case 2:

            // sub function to calculate 
            // difference
            c.result();
            std::cout << "Result: " <<
                c.sub() << std::endl;
            break;
        case 3:
            c.result();

            // mul function to calculate product
            std::cout << "Result: " <<
                c.mul() << std::endl;
            break;
        case 4:
            c.result();

            // div function to calculate division
            std::cout << "Result: " <<
                c.div() << std::endl;
            break;
        }

    } while (ch >= 1 && ch <= 4);

    return 0;

    return 0;
}