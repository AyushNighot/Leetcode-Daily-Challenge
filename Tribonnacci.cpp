Intuition
-> The Tribonacci sequence calculates the sum of the previous three numbers to generate the next one.
-> So the very first first approach that came into my mind was a recursive solution.

---------------------------------------------------------------------------------------------------------------------------------------------------------

Approach :-

Three approaches are used:
-> Recursion where each call sums the previous three calls. (But it gives a TLE)

-> Memoization to store already computed values for faster access.

-> Tabulation which iteratively fills an array to compute the sequence.

-> The space-optimized approach maintains only the necessary previous values while iterating through the sequence.

-----------------------------------------------------------------------------------------------------------------------------------------------------------

Complexity :-
Time complexity: O(n)
Space complexity: O(1)
NOTE: These are the time and space complexities of the most optimized solution i.e. Space optimization method.

-----------------------------------------------------------------------------------------------------------------------------------------------------------

Code
class Solution {
private:
    int tabulation(int n, vector<int>& dp) {
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;

        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }

        return dp[n];
    }

    int memoziation(int n, vector<int>& dp) {
        if(n <= 1)  return n;
        if(n == 2)  return 1;

        // if the value is previously computed, the recursive call will not be called
        if(dp[n] != -1) return dp[n];

        dp[n] = memoziation(n-1, dp)+memoziation(n-2, dp)+memoziation(n-3, dp);

        return dp[n];
    }

    int recursive(int n) {
        // base cases
        if(n <= 1)  return n;
        if(n == 2)  return 1;

        return recursive(n-1)+recursive(n-2)+recursive(n-3);
    }

public:
    int tribonacci(int n) {
        // return recursive(n);

        // To optimize we create a dp array which store previously computed values
        // vector<int> dp(n+1, -1);
        // return memoziation(n, dp);

        // vector<int> dp(n+1, 0);
        // return tabulation(n, dp);

        //space optimization
        if(n <= 1)  return n;
        if(n == 2)  return 1;

        int prev1 = 1, prev2 = 1, prev3 = 0;
        for(int i=3; i<=n; i++) {
            int curr = prev1+prev2+prev3;

            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }   
};
