Intuition
The intuition behind this solution is to iterate through the given string and for each character,
determine the count of consecutive characters within a range of k characters by checking alphabetically to the left and right of the current element until k and keeping the maximum count.
We then update the count of the current character based on the maximum count of surrounding characters.
-----------------------------------------------------------------------------------------------------------------------------------------------------------
Approach
Create a function checkCnt to calculate the count of consecutive characters within a range of k characters for a given index.
Iterate through the string s.
For each character, calculate the count of consecutive characters within the range using the checkCnt function and update the count array.
Finally, find the maximum count in the count array.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Complexity
Time complexity: O(n), where n is the length of the input string s. We iterate through the string once to calculate the count of consecutive characters.
Space complexity: O(1), since we are using a fixed-size array of size 26 to store the count of characters, which is independent of the input size.

---------------------------------------------------------------------------------------------------------------------------------------------------------------
Code
class Solution {
public:
    // Function to check the count of consecutive characters within a range
    int checkCnt(int idx, int k, vector<int>& cnts){
        int ans = 0, cnt=0;
        int currIdx = idx;
        // Count consecutive characters to the left
        while(currIdx >= 0 && cnt<=k){
            ans = max(ans, cnts[currIdx]);
            currIdx--;
            cnt++;
        }
        currIdx = idx;
        cnt = 0;
        // Count consecutive characters to the right
        while(currIdx<26 && cnt<=k){
            ans = max(ans, cnts[currIdx]);
            currIdx++;
            cnt++;
        }
        return ans;
    }

    // Function to find the length of the longest "ideal" string
    int longestIdealString(string s, int k) {
        // Array to store the count of characters
        vector<int> cnts(26, 0);
        int ans = 0;
        // Iterate through the string
        for(int i=0; i<s.size(); i++){
            int idx = s[i]-'a';
            // Update count of current character based on surrounding characters
            cnts[idx] = checkCnt(idx, k, cnts)+1;
        }
        // Find the maximum count in the count array
        for(int i=0; i<cnts.size(); i++){
            ans = max(ans, cnts[i]);
        }
        return ans;
    }
};
