Problem Link: https://leetcode.com/problems/assign-cookies

**********************************************************************************************************

Intuition  

For any x cookie size, try to satisfy the maximum possible greed y of left over children. [y <= x] | GREED <= SIZE

*********************************************************************************************************
   
Approach

Sort both the GREED [ g ] and COOKIE SIZE [ s ] array in descending order.
Now for some cookie size s[j], we will satisfy the child with maximum greed that can be satisfied. g[i] <= s[j]

If some greed g[i] cannot be satisfied with left over cookie size, we skip the child.

************************************************************************************************************

Complexity

Time complexity: O(N logN) : n.logn for sorting, n for array traversal

Space complexity: O(N) : Inbuilt sorting function

************************************************************************************************************
Code :-

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        for(int j=0; i<g.size() && j<s.size(); j++)
	        if(g[i]<=s[j]) i++;
        return i;
    }
};

