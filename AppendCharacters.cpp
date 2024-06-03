✅Approach:
Two Pointers: Imagine you have two pointers, one for each string. One pointer starts at the beginning of s (let's call it i), and the other at the beginning of t (let's call it j).

Matching Characters:

You move through both strings, one character at a time.
If the characters pointed to by i and j match (i.e., s[i] == t[j]), it means you've found this character of t in s, so you move both pointers forward (i and j).
If they don't match, you only move the pointer for s forward (i), because you need to keep looking for the current character of t in the remaining part of s.
End of the Loop:

If you finish scanning s and there are still some characters left in t (i.e., j is not at the end of t), it means those characters were not found in s.
The number of characters remaining in t that were not matched is len(t) - j.
Let's walkthrough🚶🏻‍♂️ the implementation process with an example for better understanding🎯:
For s = "abcde" and t = "aeb":

i = 0, j = 0: s[i] = 'a', t[j] = 'a' -> match, move both pointers (i = 1, j = 1)
i = 1, j = 1: s[i] = 'b', t[j] = 'e' -> no match, move i (i = 2)
i = 2, j = 1: s[i] = 'c', t[j] = 'e' -> no match, move i (i = 3)
i = 3, j = 1: s[i] = 'd', t[j] = 'e' -> no match, move i (i = 4)
i = 4, j = 1: s[i] = 'e', t[j] = 'e' -> match, move both pointers (i = 5, j = 2)
At this point, i has reached the end of s, but j has not reached the end of t. The remaining character in t is "b", so we need to append this character to s. Therefore, the output is 1.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Code:
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;  // Start both pointers at the beginning of s and t
        
        while (i < s.length() && j < t.length()) {  // Continue until one of the strings is fully scanned
            if (s[i] == t[j]) {  // If characters match
                j++;  // Move the pointer in t forward
            }
            i++;  // Always move the pointer in s forward
        }
        
        return t.length() - j;  // The number of characters in t not matched in s
    }
};
