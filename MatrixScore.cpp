Intuition
The primary intuition behind maximizing the score of a binary matrix is based on the value contribution of each bit in a binary number. In a binary number, the leftmost bit (most significant bit, MSB) has the highest value (2 to the power of its position). Therefore, ensuring that this bit is maximized (i.e., set to 1) across all rows will greatly increase the overall sum when these rows are interpreted as binary numbers.
Approach
Maximize MSBs Across All Rows:

Initial Check: For each row, check if the first bit (MSB) is 0.
Flip Rows: If the MSB of any row is 0, flip the entire row. This ensures that the highest value bit in every row contributes the maximum possible value.
Optimize Columns for Maximum 1s:

Column Iteration: After ensuring all rows start with a 1, examine the remaining columns from the second to the last.
Majority Check: For each column, check if the number of 0s exceeds the number of 1s.

Flip Columns: If flipping a column results in more 1s than 0s, proceed to flip it. This strategy increases the binary value of more rows since each column beyond the first still contributes significantly to the total score.

Calculate the Final Score:

Binary to Decimal: Convert each row to its decimal equivalent by interpreting it as a binary number.

Summation: Sum these decimal values to get the total score of the matrix after all optimizations.

Complexity
Time complexity:
O(N^2)

Space complexity:
O(1)

Code
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int nRows = grid.size(), nCols = grid[0].size();

        // Flipping a row
        auto flipRow = [&](int row) {
            for (int col = 0; col < nCols; ++col) {
                grid[row][col] = 1 - grid[row][col];
            }
        };

        // Flipping a column
        auto flipCol = [&](int col) {
            for (int row = 0; row < nRows; ++row) {
                grid[row][col] = 1 - grid[row][col];
            }
        };

        // Convert row to decimal
        auto checkRow = [&](const vector<int>& nums) {
            int result = 0;
            for (int num : nums) {
                result = result * 2 + num;
            }
            return result;
        };

        // Ensuring the first column has all 1s
        for (int row = 0; row < nRows; ++row) {
            if (grid[row][0] == 0) {
                flipRow(row);
            }
        }

        // Optimize columns for maximum number of 1s
        for (int col = 1; col < nCols; ++col) {
            int countOne = 0;
            for (int row = 0; row < nRows; ++row) {
                if (grid[row][col] == 1) {
                    countOne++;
                }
            }
            if (countOne * 2 < nRows) { // More 0s than 1s
                flipCol(col);
            }
        }

        // Calculate the total 

        int totalScore = 0;
        for (const auto& row : grid) {
            totalScore += checkRow(row);
        }

        return totalScore;
    }
};
