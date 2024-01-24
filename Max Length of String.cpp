Problem Link:- https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

//////////////////////////////////////////////////////////////////////////////////////////////

Approach

Explanation:
solve function:

Takes three parameters - arr (vector of strings), str (current string being constructed), and index (index of the next word to be added from the vector).
Creates an unordered set uset containing unique characters from the current string str.
Checks if the length of the string is equal to the size of the set. If not, it means there are duplicate characters, and the function returns 0.
Initializes the answer ans with the length of the current string.
Iterates over the remaining words in the vector arr starting from the given index.
Recursively calls solve by appending each word to the current string, updating the index for the next iteration, and updating the maximum length obtained so far.
maxLength function:

Invokes the solve function to start the recursion with an empty string ("") and an initial index of 0.
Returns the result obtained from the recursive exploration, which represents the maximum possible length of a string constructed from the given vector of words.
This code essentially explores all possible combinations of words from the vector arr to form a string while ensuring that each character in the string is unique. It uses backtracking and recursion to explore all possible combinations and returns the maximum length obtained. The unordered_set is used to check for duplicate characters in the current string.

/////////////////////////////////////////////////////////////////////////////////////////////////////

Complexity :-

Space complexity:0(N)

//////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
int solve(vector<string>& arr , string str , int index)
{
    unordered_set<char>uset(str.begin(),str.end());
    if((int)str.length() != uset.size())
    {
        return 0 ;
    }
    int ans = str.length();
    for(int i = index;i < arr.size();i++)
    {
        ans = max(ans,solve(arr,str + arr[i],i+1));   
    }
    return ans ; 
}

    int maxLength(vector<string>& arr) {
        return solve(arr, "", 0 );
    }
};