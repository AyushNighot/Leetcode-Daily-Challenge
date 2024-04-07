Note:
First, I want to provide you with a direct link to another approach using range of Lee215, who is the best leetcoder: Link
With my solution, I use stack approach for beginners to understand easily and actually for interview.
Please upvote if you found it helpful !
Step by step
Using 2 stacks contain index of '*' and '('
Go through string s
If s[i] is '(', push the index i into stack '('
If s[i] is '*', push the index i into stack '*'
If s[i] is ')', check '(' or '*' appear in stacks. If not -> return false. If yes -> pop()
Check if index of '(' is smaller than index of '*'(which means '(' appears before '*'). If not -> return false.

--------------------------------------------------------------------------------------------------
Example
s = "* ( ( ) ( *"
     0 1 2 3 4 5

After step 1-5:
stack* = 0 5
stack( = 1 4

Step 6: 
Because 0 < 1 -> '*' appears before '(' -> return false
---------------------------------------------------------------------------------------------------------
Complexity
Time complexity: O(n)O(n)O(n)
Space complexity: O(n)O(n)O(n) where stack contains up to n characters

---------------------------------------------------------------------------------------------
Code
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> starIndex;
        stack<int> stackIndex;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                stackIndex.push(i);
            }
            else if(s[i] == '*')
            {
                starIndex.push(i);
            }
            else if(s[i] == ')')
            {
                if(stackIndex.empty() && starIndex.empty()) 
                    return false;
                else if(!stackIndex.empty()) 
                    stackIndex.pop();
                else    
                    starIndex.pop();;
            }
        }

        while(!stackIndex.empty())
        {
            if(starIndex.empty()) return false;
            if(stackIndex.top() > starIndex.top()) return false;
            stackIndex.pop();
            starIndex.pop();
        }

        return true;
    }
};
