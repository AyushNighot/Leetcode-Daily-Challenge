Approach:

countimg subarrays with AtMost k distinct - AtMost (k-1) distinct elements
if a subarray has AtMost k distinct then it means all subarrays that either have [1 distinct, 2 distinct, .... or k distinct] elements will be part of it, now if we reduce count of subarray that either have [1 distinct, 2 distinct, .... or (k-1) distinct] elements, it should give us a count of subarrays which have exactly k distinct elements.
number of new subarrays formed with addition of 1 element in end = j-i+1
class Solution {
public:
    
    int countSubarraysWithAtMostKDistinct(vector<int>& nums, int k){
        int n=nums.size();
        
        unordered_map<int, int> mp;
        
        int i=0, j=0;
        
        int c=0;
        
        while(j<n){
            mp[nums[j]]++;
            
            while(i<=j && mp.size()>k){
                if(--mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            
            c += (j-i+1);
            
            j++;
        }
        
        return c;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarraysWithAtMostKDistinct(nums,k)-countSubarraysWithAtMostKDistinct(nums,k-1);
    }
};
