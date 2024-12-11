class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int j=0,sum=0,ans=0;
        for(int i=0;i<n;i++){
            while(nums[j]+ 2*k < nums[i]){
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
