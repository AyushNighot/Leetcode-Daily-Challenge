Complexity
Time Complexity:

Counting characters in each word: O(n * m), where n is the number of words and m is the average length of the words.
Updating the reference frequency array: O(n * 26), since we compare 26 possible characters for each word.
Constructing the result list: O(26), iterating through the frequency array to build the result.
Overall, the time complexity is O(n * m), where n is the number of words and m is the length of the longest word.
Space Complexity:

The space required for the frequency arrays is O(26) for each word.
Additional space for the result list depends on the number of common characters, which is O(m) in the worst case (though typically much smaller).
Overall, the space complexity is O(26) + O(m) = O(m).

=============================================================================================================================
Code
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> last = count(words[0]);
        for (int i = 1; i < words.size(); i++) {
            last = intersection(last, count(words[i]));
        }
        
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (last[i] > 0) {
                result.push_back(string(1, 'a' + i));
                last[i]--;
            }
        }
        
        return result;
    }
    
private:
    vector<int> count(const string& str) {
        vector<int> frequency(26, 0);
        for (char c : str) {
            frequency[c - 'a']++;
        }
        return frequency;
    }
    
    vector<int> intersection(const vector<int>& a, const vector<int>& b) {
        vector<int> t(26, 0);
        for (int i = 0; i < 26; i++) {
            t[i] = min(a[i], b[i]);
        }
        return t;
    }
};
