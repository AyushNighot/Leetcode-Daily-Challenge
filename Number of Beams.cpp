Problem Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank

**********************************************************************************************************

Intuition 

The problem involves counting the number of laser beams that can be formed between pairs of security devices in the bank. A laser beam is possible between two devices if there are no security devices in the rows between them.

**********************************************************************************************************

Approach

1) Iterate through each row of the bank and calculate the number of security devices in that row (curRowCount).
2) For each non-empty row, calculate the number of laser beams that can be formed between devices in the current row and devices in the previous row (prevRowCount).
3) Update the total count of laser beams.
4) Return the total count.

**********************************************************************************************************

Complexity

Time complexity: O(m * n), where m is the number of rows and n is the number of columns in the bank. The solution iterates through each row and calculates the count of security devices in that row.

Space complexity: O(1), as the space used is constant, and no additional data structures are used.

*************************************************************************************************************
Code :-

class Solution {
public:
    int numberOfBeams(std::vector<std::string>& bank) {
        int prevRowCount = 0;
        int total = 0;

        for (const std::string& row : bank) {
            int curRowCount = calc(row);
            if (curRowCount == 0)
                continue;

            total += curRowCount * prevRowCount;
            prevRowCount = curRowCount;
        }
        return total;
    }

private:
    int calc(const std::string& s) {
        int count = 0;
        for (char c : s)
            count += c - '0';

        return count;
    }
}; 