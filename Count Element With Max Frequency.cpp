class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
    unordered_map <int , int >mp;
    int count = 0;
    int maxfreq = INT_MIN;
        for (auto &num : nums)
        {
            mp[num]++;
            maxfreq = max(maxfreq, mp[num]);
        }

    
        for (auto &m : mp)
        {
            if(m.second == maxfreq)
            {
                count += maxfreq;
            }
        }

        return count;
    }
};
