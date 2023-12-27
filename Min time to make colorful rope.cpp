Problem Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/solutions/4463311/leetcode-daily-problem

**********************************************************************************************************
Intuition

The problem requires minimizing the time to make a rope of balloons colorful by avoiding consecutive balloons with the same color. To achieve this, every time we get same color , remove the balloon with less time needed.

*********************************************************************************************************

Approach

   1} Iterate through the given colors and neededTime arrays, starting from the second balloon.
   2} Check if consecutive balloons have the same color (colors[i] == colors[i - 1]).
   3} If true, add the minimum time to remove between 2 balloons min(neededTime[i], neededTime[i - 1]) and adjust the time needed for the               4} current balloon (neededTime[i]) to ensure it takes at least as much time as the previous balloon (neededTime[i - 1]). i.e. max(cost[i], cost[i - 1])

****************************************************************************************************
Complexity

Time complexity:O(n)

where n = length of colors array

Space complexity:O(1)

using constant amount of extra space

******************************************************************************************************


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int time = 0;
        int n = colors.size();
        for(int i = 1; i < n; i++)
        {
            if(colors[i] == colors[i - 1])
            {
                time += min(neededTime[i], neededTime[i - 1]); 
                neededTime[i] = max(neededTime[i], neededTime[i - 1]); 
            }     
        }
        
        return time;
        
    }
};
