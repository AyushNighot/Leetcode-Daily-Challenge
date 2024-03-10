class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;

        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0; j < m ; j++)
            {
                if(nums1[i] == nums2[j] && (ans.empty() || nums1[i] != nums1[i - 1]))
                {
                    ans.push_back(nums2[j]);
                    nums2[j] = -1;
                    break;
                }
            }
        }
        return ans;
    }
};
