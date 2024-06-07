Problem Statement
We're given a dictionary of root words and a sentence. The task is to replace words in the sentence with their shortest corresponding root words from the dictionary. If a word doesn't have a root in the dictionary, it remains unchanged.

Intuition
The key idea here is to leverage a data structure that efficiently searches for prefixes of words. A trie, a tree-like structure where each node represents a character in a word, is ideal for this task. By traversing the trie for each word in the sentence, we can check if a prefix exists as a complete word in the dictionary, identifying the root for replacement.

Approach
Trie Construction:
Build a trie from the dictionary words. Each node in the trie will have an array of child nodes (one for each lowercase letter) and a boolean flag indicating if it's a complete word.
Sentence Processing:
Split the sentence into individual words.
Iterate through each word:
Traverse the trie for that word, checking if any prefix is marked as a root.
If a root is found, replace the word with that root (prioritize the shortest root in case of ambiguity).
If no root is found, keep the original word.
Result Formation:
Build the final sentence by joining the processed words with spaces.
Implementation
class Trie {
public:
    bool terminal;
    Trie* next[26]; // Array of pointers to child nodes (one for each letter)

    Trie() {
        terminal = false;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class Solution {
    Trie* root = new Trie(); // Root node of the trie

public:
    void insert(string word) {
        Trie* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->next[index]) {
                curr->next[index] = new Trie();
            }
            curr = curr->next[index];
        }
        curr->terminal = true;
    }

    string search(string word) {
        Trie* curr = root;
        int rootLength = 0;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            int index = c - 'a';
            if (!curr->next[index]) {
                return ""; // No root found
            }
            curr = curr->next[index];
            if (curr->terminal) {
                rootLength = i + 1; // Update shortest root length if found
            }
        }
        return word.substring(0, rootLength); // Return the shortest root substring
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string word : dictionary) {
            insert(word);
        }

        string[] words = sentence.split(" "); // Split sentence into words
        StringBuilder result = new StringBuilder();

        for (String word : words) {
            String root = search(word);
            result.append(root).append(" ");
        }

        return result.toString().trim(); // Remove trailing whitespace
    }
};
Complexity
Time complexity:
Trie construction: O(M * T), where M is the number of words in the dictionary and T is the average length of a word (due to iterating over each character in each word).
Sentence processing: O(N * T), where N is the number of words in the sentence (due to iterating over each word and potentially searching the trie).
Overall time complexity: O((M + N) * T) in most cases.

Space complexity:
Trie: O(M * T), as each word in the dictionary can potentially contribute to a trie node.
Code
