Problem Link:- https://leetcode.com/problems/daily-temperaturesn

///////////////////////////////////////////////////////////////////////////////////////////

Intuition
The goal is to find the number of days one has to wait until a warmer day for each given day's temperature. This can be efficiently solved using a stack.

///////////////////////////////////////////////////////////////////////////////////////////

Approach

Initialize an array results to store the number of days until a warmer day for each day's temperature.
Initialize an empty stack to keep track of indices.
Iterate through each temperature in the array.
      While the stack is not empty and the current temperature is greater than the temperature at the index on the top of the stack:
           Update the result for the index at the top of the stack with the difference between the current index and the index on the top of the stack.
           Pop the index from the stack.
     Push the current index onto the stack.
After the iteration, the results array contains the number of days until a warmer day for each given day.

////////////////////////////////////////////////////////////////////////////////////////////////
Complexity
Time complexity: O(n)O(n)O(n), where n is the number of temperatures.
Space complexity: O(n)O(n)O(n), as the stack can have at most n elements.

//////////////////////////////////////////////////////////////////////////////////////////

Code :-

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temps) {
        std::vector<int> results(temps.size());
        std::stack<int> stack;
        
        for (int i = 0; i < temps.size(); i++) {
            while (!stack.empty() && temps[stack.top()] < temps[i]) {
                results[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }

        return results;
    }
};