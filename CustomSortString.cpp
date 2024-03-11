class Solution {
public:
    string customSortString(string order, string s) {
        
        int count[26] = {0};
        string result = "";
        for (char &ch : s)
        {
            count[ch - 'a']++;
        }
        
        for (auto &ch : order)
        {
            while(count[ch - 'a'] > 0)
            {
                result.push_back(ch);
                count[ch - 'a']--;
            }
        }

        for (char &ch : s)
        {
            if(count[ch - 'a'] > 0)
            {
                result.push_back(ch);
            }
        }
        return result;
    }
};
