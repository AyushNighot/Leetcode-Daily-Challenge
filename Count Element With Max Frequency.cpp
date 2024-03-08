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


----------------------------------------------------------------------------------------- Single Pass Solution -------------------------------------------------------------------------

    class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
      vector<int> freq(101,0);  
        int maxFreq = 0;
        int total = 0;
        for (int num : nums)
        {
            freq[num]++;

            int freqq = freq[num];

            if(freqq > maxFreq)
            {
                maxFreq = freqq;
                total = maxFreq;
            }
            else if( freqq == maxFreq)
            {
                total += maxFreq;
            }
        }
        return total;
    }
};
 
