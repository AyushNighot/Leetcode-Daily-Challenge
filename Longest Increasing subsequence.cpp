Problem Link:- https://leetcode.com/problems/longest-increasing-subsequence

///////////////////////////////////////////////////////////////////////////////////////////////

Intuition

To find the length of the longest increasing subsequence (LIS), we can use dynamic programming. We'll create an array dp where dp[i] represents the length of the LIS ending at index i. We initialize all values in dp to 1 since the minimum LIS length for any element is 1.

////////////////////////////////////////////////////////////////////////////////////////////////

Approach :-

Approach
1) Initialize an array dp with the same length as nums and fill it with 1s.
2) Iterate through each element in nums.
       For each element at index i, iterate through all previous elements at indices j (where j < i).
       If nums[j] < nums[i], update dp[i] to the maximum between its current value and dp[j] + 1. This means we've found a longer           subsequence ending at index i.
3) Find the maximum value in the dp array, which represents the length of the longest increasing subsequence.
4) Return the maximum value.

//////////////////////////////////////////////////////////////////////////////////////////////

Complexity

Time complexity: O(n^2) - Two nested loops are used to iterate through the elements.
Space complexity: O(n) - Additional space is used for the dp array.

//////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
    public int lengthOfLIS(int[] nums) {
        // Initialize an array dp with the same length as nums and fill it with 1s
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1);

        // Iterate through each element in nums
        for (int i = 1; i < nums.length; i++) {
            // Iterate through all previous elements
            for (int j = 0; j < i; j++) {
                // If nums[j] < nums[i], update dp[i]
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                }
            }
        }

        // Find the maximum value in the dp array
        int maxLength = 0;
        for (int len : dp) {
            maxLength = Math.max(maxLength, len);
        }

        // Return the maximum value
        return maxLength;
    }
}




