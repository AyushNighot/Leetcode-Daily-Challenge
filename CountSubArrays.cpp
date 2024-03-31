//Approach-1 (Brute Force)
//Find all subarrays and check if min is minK and max is maxK


-----------------------------------------------------------------------------------------------
//Code will be provided soon for brute force

//Approach-2 (Optimal O(n)) - Sliding Window


    
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        long long ans = 0;

        int minKpos = -1;
        int maxKpos = -1;
        int culprit = -1;


        for (int i = 0 ; i < nums.size() ; i++)
        {

            if(nums[i] < minK || nums[i] > maxK)
             culprit = i;

            if(nums[i] == minK )
             minKpos = i;

             if(nums[i] == maxK)
             maxKpos = i;

             long long smaller = min(minKpos,maxKpos);

             long long temp = smaller - culprit;

             ans += (temp <= 0) ? 0 :temp;
        }   
        return ans;     
    }
};
