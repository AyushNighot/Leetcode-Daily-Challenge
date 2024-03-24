class Solution {
public:



    int findDuplicate(vector<int>& nums) 
    {
         map<int, int> m;
        int dplicate = 0;

        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        for(auto i: m) 
        {
            if(i.second > 1) 
            {
                dplicate= i.first;
                break;
            }
        }
        return dplicate;
    }
};


        /*
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums [nums[fast]];
        } while(slow != fast);

        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        */
