Problem Link:- https://leetcode.com/problems/evaluate-reverse-polish-notation
///////////////////////////////////////////////////////////////////////////////////////////

Intuition
To solve the problem, we need to evaluate expressions written in Reverse Polish Notation (RPN). RPN expressions have operators placed after their operands, making it convenient to calculate using a stack.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Approach
Here's how we solve the problem:

We start with an empty stack to hold numbers.
We go through each part of the RPN expression:
If we encounter an operator, we take the last two numbers from the stack, perform the operation, and put the result back in the stack.
If we find a number, we simply put it in the stack.
After going through all parts of the expression, the final result is the only number left in the stack.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Complexity
Time complexity:
It's O(n), where n is the number of parts (operators and numbers) in the expression.
Space complexity:
It's also O(n) due to the stack. We might have around n/2 elements in the stack when we process a long sequence of operators and numbers.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
C++ Code
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto a : tokens) {
            if (a.size() == 1 && !isdigit(a[0])) {  // check if an operator
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                switch (a[0]) {  // note switch use char or integer
                    case '+':
                        s.push(num1 + num2);
                        break;
                    case '-':
                        s.push(num1 - num2);
                        break;
                    case '*':
                        s.push(num1 * num2);
                        break;
                    case '/':
                        s.push(num1 / num2);
                        break;
                }
            } else {  // if an number push to stack
                s.push(atoi(a.c_str()));
            }
        }
        return s.top();
    }
};