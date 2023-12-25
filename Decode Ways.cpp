Problem Link:- https://leetcode.com/problems/decode-ways/description/

///////////////////////////////////////////////////////////////////////////////////////////////

Approach - Bottom-up Dynamic Programming for Decoding
1. Initialize Variables: Set three variables (a, b, and c) to 1.

2. Iterate Through String: Use a loop to traverse the input string, starting from the second character.

3. Check for Invalid Decoding: Check for cases where a '0' follows an invalid grouping of digits. Return 0 if such a scenario occurs.

4. Update Counts for Valid Two-Digit Mapping: If the previous character is not '0' and the current two-digit grouping is valid, update counts based on the presence of zeros.

   If the current character is '0', swap and update variables (c, b, a) accordingly.
   If the current character is not '0', update variables (c, b, a) for non-zero cases.
5. Handle One-Digit Mapping: If the two digits do not form a valid mapping, update only b.

6. Check for Invalid Starting Character: If the first character is '0', return 0.

7. Return Result: Return the final count (a).

//////////////////////////////////////////////////////////////////////////////////////////////////

Time complexity: O(n)
The algorithm iterates through the given string of length n once.
Each iteration involves constant time operations.

Space complexity: O(1)
The algorithm uses only a constant number of variables (a, b, c) regardless of the input size.
The space required is independent of the length of the input string.
/////////////////////////////////////////////////////////////////////////////////////////////////

Code :-

      class Solution {
public:
    int numDecodings(string s) {
          // Initialize variables to represent counts of decoding ways
        int a = 1;  // Represents the number of ways to decode the string ending at the current character
        int b = 1;  // Represents the number of ways to decode the string ending at the previous character
        int c = 0;  // Temporary variable for swapping during zero-handling

        // Iterate through the string starting from the second character
        for (int i = 1; i < s.length(); i++) {
            // Check for invalid decoding (e.g., '30' or '40-90')
            if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] < '1')) {
                return 0;
            }
            // Check for valid two-digit mapping
            else if (s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + (s[i] - '0')) < 27) {
                // Handle zero in the current digit
                if (s[i] == '0') {
                    c = b;
                    b = a;
                    a = c;
                    continue;
                }
                // Update counts for non-zero cases
                else {
                    c = b;
                    b = a;
                    a = a + c;
                    continue;
                }
            }
            // Handle one-digit mapping
            else {
                b = a;
                continue;
            }
        }

        // Check for invalid starting character
        if (s[0] == '0') {
            return 0;
        }

        // Return the final count representing the total number of ways to decode the string
        return a;
    }
};