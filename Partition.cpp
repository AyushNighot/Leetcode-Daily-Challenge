Approach :-
Backtracking:

We use a backtracking approach to explore all possible partitions of the string.
= The idea is to generate substrings starting from each index and checking if the substring is a palindrome.

If the substring is a palindrome, we recursively explore further partitions from the end of the current substring.
Recursive Function:

Define a helper function explore(index, curr) where index is the starting point for generating substrings, and curr is the current list of substrings.

If index reaches the end of the string (index >= lenS), it means we have a valid partition, so we append a copy of curr to the result list.

For each possible ending index i starting from index, generate the substring s[index:i+1].

Check if the substring is a palindrome (subStr == subStr[::-1]).

If it is, add the substring to curr, recursively call explore(i + 1, curr), and then backtrack by removing the last substring added to curr.

Base Case and Recursive Case:

Base Case: When index is equal to the length of the string, we have considered all characters, so we add the current partition (curr) to the result.
Recursive Case: Iterate through possible substrings, check if they are palindromes, and recursively partition the rest of the string.
Complexity
Time complexity:
O(2^N)

Space complexity:
O(2^N)
-----------------------------------------------------------------------------------------------------------------------------------------------
Code
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        int lenS = s.length();

        function<void(int)> explore = [&](int index) {
            if (index >= lenS) {
                result.push_back(curr);
                return;
            }

            for (int i = index; i < lenS; ++i) {
                string subStr = s.substr(index, i - index + 1);
                if (isPalindrome(subStr)) {
                    curr.push_back(subStr);
                    explore(i + 1);
                    curr.pop_back();
                }
            }
        };

        explore(0);
        return result;
    }

private:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};
