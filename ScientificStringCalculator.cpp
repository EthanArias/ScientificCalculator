#include "ScientificStringCalculator.h"
void ScientificStringCalculator::set(std::string expression)
{
    int i;

    // stack to store integers and operators. 
    std::queue <std::string> stack;
    std::stack<char> ops;

    for (i = 0; i < expression.length(); i++) {
        // if token blank, skip 
        if (expression[i] == ' ')
            continue;
        // if token is a number, add to stack
        else if (isdigit(expression[i])) {
            int val = 0;

            // single or double digit number.
            while (i < expression.length() &&
                isdigit(expression[i]))
            {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }

            stack.push(std::to_string(val));
            stack.push(" ");
        }
        // if token '(' add to stack
        else if (equation[i] == '(') {
            ops.push(equation[i]);
        }
        // if token ')', solve entire brace. 
        else if (expression[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                stack.push(std::to_string(ops.top()));
                ops.pop();
                stack.push(" ");
            }

            // pop opening brace. 
            ops.pop();
        }
        else {
            while (!ops.empty() && operators(ops.top()) >= operators(expression[i])) {
                stack.push(std::to_string(ops.top()));
                ops.pop();
                stack.push(" ");
            }
            ops.push(expression[i]);
        }
    }
    while (!ops.empty())
    {
        stack.push(std::string{ ops.top() });
        ops.pop();
        stack.push(" ");
    };
    std::string resultString = "";
    while (!stack.empty()) {
        resultString += stack.front();
        stack.pop();
    }
    equation = resultString;
}

inline ScientificStringCalculator::ScientificStringCalculator()
{
    equation = "";
}

inline ScientificStringCalculator::ScientificStringCalculator(std::string expression)
{
    set(expression);
}

inline void ScientificStringCalculator::operator()()
{
    equation = "";
}

inline void ScientificStringCalculator::operator()(std::string expression)
{
    set(expression);
}

int ScientificStringCalculator::evaluate()
{
    int i;

    // stack to store integers and operators. 
    std::stack<int> numbers;
    std::stack<char> ops;

    for (i = 0; i < equation.length(); i++) {

        // if token blank, skip 
        if (equation[i] == ' ')
            continue;

        // if token '(' add to stack
        else if (equation[i] == '(') {
            ops.push(equation[i]);
        }

        // if token is a number, add to stack
        else if (isdigit(equation[i])) {
            int val = 0;

            // single or double digit number.
            while (i < equation.length() &&
                isdigit(equation[i]))
            {
                val = (val * 10) + (equation[i] - '0');
                i++;
            }

            numbers.push(val);
        }

        // if token ')', solve entire brace. 
        else if (equation[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = numbers.top();
                numbers.pop();

                int val1 = numbers.top();
                numbers.pop();

                char op = ops.top();
                ops.pop();

                numbers.push(maths(val1, val2, op));
            }

            // pop opening brace. 
            ops.pop();
        }

        // Current token is an operator. 
        else
        {

            while (!ops.empty() && operators(ops.top())
                >= operators(equation[i])) {
                int val2 = numbers.top();
                numbers.pop();

                int val1 = numbers.top();
                numbers.pop();

                char op = ops.top();
                ops.pop();

                numbers.push(maths(val1, val2, op));
            }

            // Push current token to 'ops'. 
            ops.push(equation[i]);
        }
    }

    //Do remaining operations 
    while (!ops.empty()) {
        int val2 = numbers.top();
        numbers.pop();

        int val1 = numbers.top();
        numbers.pop();

        char op = ops.top();
        ops.pop();

        numbers.push(maths(val1, val2, op));
    }

    // Top of 'numbers' contains result, return
    return numbers.top();
}

inline std::string const ScientificStringCalculator::GivePostFix()
{
    return equation;
}

std::string const ScientificStringCalculator::GiveInFix()
{
    std::stack<std::string> s;
    std::string postfix = equation;

    for (char c : postfix) {
        if (isalnum(c)) {
            s.push(std::string(1, c)); // Convert char to string
        }
        else if (operators(c)!=0) {
            if (s.size() < 2) {
                return "Invalid Expression"; // Handle insufficient operands
            }
            std::string operand2 = s.top(); s.pop();
            std::string operand1 = s.top(); s.pop();
            s.push("(" + operand1 + c + operand2 + ")");
        }
    }

    if (s.size() != 1) {
        return "Invalid Expression"; // Handle remaining elements
    }

    return s.top();
}
