#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>

class ScientificStringCalculator
{
public:
    inline ScientificStringCalculator();
    inline ScientificStringCalculator(std::string expression);
    inline void operator() ();
    inline void operator() (std::string expression);
    int evaluate();
    inline std::string const GivePostFix();
    std::string const GiveInFix();
private:
    // Finding operators 
    inline int operators(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/' || op == '%')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    };
    // The maths
    inline int maths(int a, int b, char op) {
        switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        case '^': return pow(a,b);
        }
        return 0;
    };
    void set(std::string expression);
    std::string equation;
};