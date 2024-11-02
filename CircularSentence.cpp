class Solution {
public:
    bool isCircularSentence(string& sentence) {
        string_view s(sentence);
        if (s[0]!=s.back()) return 0;
        int split=-1;
        while(1){
            split=s.find(' ', split+1);
            if (split==-1) break;
            if (s[split-1]!=s[split+1]) return 0;
        }
        return 1;
    }
};
