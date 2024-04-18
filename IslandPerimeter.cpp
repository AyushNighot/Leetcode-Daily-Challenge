Intuition 🌊
To determine the perimeter of the island, we need to count the number of edges that are exposed to water. We can achieve this by iterating over each land cell and checking its adjacent cells. If the adjacent cell is water or out of bounds, we increment the perimeter count.

Approach 🛶
Initialize two variables: islands to count the number of land cells encountered and neighbors to count the number of adjacent land cells.
Iterate over each cell of the grid.
For each land cell encountered, increment the islands count.
Check the adjacent cells (up and left) and increment the neighbors count accordingly.
Finally, return the total perimeter count using the formula islands * 4 - neighbors * 2.
Complexity Analysis 📊
Time complexity: O(N×M)O(N \times M)O(N×M), where NNN is the number of rows and MMM is the number of columns in the grid.
Space complexity: O(1)O(1)O(1).
cutecat upvote.jpg

Code
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islands = 0;
        int neighbors = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    islands++;
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                        neighbors++;
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                        neighbors++;
                    }
                }
            }
        }

        return islands * 4 - neighbors * 2;
    }
};
