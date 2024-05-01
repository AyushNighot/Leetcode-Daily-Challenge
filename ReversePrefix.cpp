✅Approach:
Iterate Through the String:

Start by iterating through the given string word character by character until you find the target character ch.
If the character ch is not found, return the original string word.
Reverse the Prefix:

Once the target character ch is found, reverse the substring from the beginning of the string up to and including the index of ch.
You can use slicing or other methods available in the programming language to reverse the substring.
Concatenate the Reversed Prefix with the Remaining String:

After reversing the prefix, concatenate it with the remaining part of the string after the index of ch.
This can be done using string concatenation or string joining methods depending on the programming language.
Return the Modified String:

Finally, return the modified string after reversing the prefix up to the first occurrence of the target character ch.

---------------------------------------------------------------------------------------------------------------------------
Code👩🏻‍💻:
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = word.find(ch);
        if (j != -1) {
            reverse(word.begin(), word.begin() + j + 1);
        }
        return word;
    }
};
