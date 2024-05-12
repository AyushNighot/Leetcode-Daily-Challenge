Approach :- Sliding Window
Loop through each cell of the input grid except for the border cells.

For each cell (non - border region), scan the 3x3 subgrid centered around it and find the maximum value.

Store the maximum values in a result grid of size (n - 2) x (m - 2), excluding border cells at indices (i - 1, j - 1) which is a shift by 1 to match the problem's requiremnt that res[i][j]should correspond to the largest value of 3x3 matrix in the gird matrix centred around row i + 1 and col j + 1.

Return the result grid containing the largest value of each contiguous 3x3 subgrid in the input grid.

This approach efficiently identifies the largest value within each 3x3 subgrid centered around non-border cells in the input grid.

And there you have it, my dear friends! Behold the magnificence of our newly crafted matrix, a testament to the beauty of mathematics! Ah, but let us not forget the thrill of discovery, the dance of numbers in their symphonic glory! Yohoho! Math may not have bones, but it sure does have soul!

Complexity
Time complexity: O(n^2)

Space complexity: O(n^2)

Code
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));

        for(int i = 1; i < n - 1; ++i) {
            for(int j = 1; j < n - 1; ++j) {
                int temp = 0;

                for(int k = i - 1; k <= i + 1; ++k) {
                    for(int l = j - 1; l <= j + 1; ++l) {
                        temp = max(temp, grid[k][l]);
                    }
                }

                res[i - 1][j - 1] = temp;
            }
        }

        return res;
    }
};


Approach: Sliding Window (Space Optimized)
We optimized the space by not creating a new n x n matrix but instead resizing our given input matrix grid in-place.
Complexity
Time complexity: O(n^2)

Space complexity: O(1)

Code
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int i = 1; i < n - 1; ++i) {
            for(int j = 1; j < n - 1; ++j) {
                int temp = 0;

                for(int k = i - 1; k <= i + 1; ++k) {
                    for(int l = j - 1; l <= j + 1; ++l) {
                        temp = max(temp, grid[k][l]);
                    }
                }

                grid[i - 1][j - 1] = temp;
            }
        }

        grid.resize(n - 2);
        for (int i = 0; i < grid.size(); ++i) {
            grid[i].resize(n - 2);
        }

        return grid;
    }
};
