class Solution {
private:
    void f(int index, vector<int>& nums, vector<int>& t, vector<vector<int>>& ans){
        ans.push_back(t);

        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]) continue;
            t.push_back(nums[i]);
            f(i + 1, nums, t, ans); 
            t.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;

        sort(nums.begin(), nums.end());
        f(0, nums, t, ans);
        return ans;
    }
};



