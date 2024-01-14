Problem Link:- https://leetcode.com/problems/determine-if-two-strings-are-close

///////////////////////////////////////////////////////////////////////////////////////////////

Problem Statement
Two strings are considered close if you can attain one from the other using the following operations:

     1) Operation 1: Swap any two existing characters.
     2) Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

////////////////////////////////////////////////////////////////////////////////////////////////

Approach

  1) Check if the lengths of word1 and word2 are equal. If not, return false because it is not possible to transform one string into the other with different lengths.
  2) Count the frequency of each character in both word1 and word2.
  3) For each character in the alphabet, check if it appears in either word1 or word2 but not in both. If yes, return false because the set of characters must be the same for both strings.
  4) Sort the frequency arrays of both word1 and word2. This is done to compare if the frequency of each character is the same in both strings.
  5) Iterate through the sorted frequency arrays and check if the frequencies are equal for each character. If not, return false.
  6) If the loop completes without returning false, return true.

////////////////////////////////////////////////////////////////////////////////////////////////

Complexity Analysis
The time complexity is O(n), where n is the length of word1 or word2.
The space complexity is O(1) because the size of the alphabet (26) is constant.

///////////////////////////////////////////////////////////////////////////////////////////////

Code:--

class Solution {
    public boolean closeStrings(String word1, String word2) {
        if (word1.length() != word2.length())
            return false;

        int[] f1 = new int[26];
        int[] f2 = new int[26];

        // Count frequency of each character in both words
        for (int i = 0; i < word1.length(); i++) {
            f1[word1.charAt(i) - 'a']++;
            f2[word2.charAt(i) - 'a']++;
        }

        // Check if the set of characters is the same for both words
        for (int i = 0; i < 26; i++) {
            if ((f1[i] == 0 && f2[i] != 0) || (f1[i] != 0 && f2[i] == 0))
                return false;
        }

        // Sort frequency arrays
        Arrays.sort(f1);
        Arrays.sort(f2);

        // Check if the frequency of each character is the same
        for (int i = 0; i < 26; i++) {
            if (f1[i] != f2[i])
                return false;
        }

        return true;
    }
}