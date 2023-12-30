Problem Link:- https://leetcode.com/problems/redistribute-characters-to-make-all-strings

///////////////////////////////////////////////////////////////////////////////////////////////

Approach :-

1)  Counting Characters: It iterates through each word in the words vector and counts the occurrences of each character, storing the counts in an unordered map counts.

2) Checking if Characters Can Be Distributed Equally: Then, it checks if the count of each character in the counts map is divisible by the total number of words n. If any character count isn't evenly divisible by n, it returns false. If all characters meet this condition, it returns true.

//////////////////////////////////////////////////////////////////////////////////////////////

Complexity :-

Time complexity:

O(n).k

Space complexity:
O(1)

//////////////////////////////////////////////////////////////////////////////////////////////

Code :-
class Solution {
public:
    bool makeEqual(vector<string>& words)
 {
        unordered_map<char, int> counts;
        for (auto a  : words) {
            for (char x : a) {
                counts[x]++;
            }
        }
        
        int n = words.size();
        for (auto a : counts) {
            if (a.second % n != 0) 
            {
                return false;
            }
        }
        
        return true;
    }
};

 

