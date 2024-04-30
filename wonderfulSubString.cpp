Intuition

We are concerned with whether each letter in the substring has an odd or even count.
Consider the example acabc:
Here a appears even times, b appears odd times, and c appears even times => We can represent this state as 010.
To get an all even appearances substring with current end, we can remove any prefix string with the same state 010
odd - odd = even
even - even = even
To get exactly one odd appearance substring with current end, we try considering each letter as the odd one and flip its bit in the state while keeping the other bits intact.
Let try to find substring with a is the odd one, flip the a bit then we get state 110, so we can remove any prefix string that have state 110 to get a suitable substring.
odd - even = odd
even - odd = odd
With only 10 letters (a to j), our states have a length of 10, resulting in 1024 possible states.
=> We can manage the count of each state using an array of 1024 integers and perform bit manipulation to update these counts.
Assign a -> j = 2^0 -> 2^9 = 1 << 0 -> 1 << 9
To flip / toggle the odd or even status of a letter within a state, we perform bitwise XOR operations with the corresponding value of the letter.

------------------------------------------------------------------------------------------------------------------------------------------
Approach
We maintain an array of 1024 integers to count the number of prefix strings with each state.
Initially, all letters have zero appearances, represented by the state 0000000000 or simply 0, with a count of 1.
Iterate through each letter in word:
Update the current state accordingly.
Increment the result by the count of all even appearance substrings count[currentState].
Iterate over all letters from a to j and update the result by considering each letter as the only one with an odd appearance:
Compute the oddState by flipping the bit of the current letter.
Add the count of substrings with this odd state to the result count[oddState].

-----------------------------------------------------------------------------------------------------------------------------------------------
Complexity :-

Time complexity: O(n)O(n)O(n)
Space complexity: O(2c)O(2 ^ c)O(2 c), c is number of letters from 'a' to 'j'

-----------------------------------------------------------------------------------------------------------------------------------------------
Code
class Solution {
public:
    int get(char c) {
        return c - 'a';
    }

    long long wonderfulSubstrings(string word) {
        vector<long long> cnt(1024, 0);
        cnt[0] = 1;

        int curState = 0;
        long long res = 0;

        for (char c : word) {
            curState ^= 1 << get(c);

            res += cnt[curState];
            for (char odd = 'a'; odd <= 'j'; odd++) {
                int oddState = curState ^ (1 << get(odd));
                res += cnt[oddState];
            }

            cnt[curState]++;
        }

        return res;
    }
};
