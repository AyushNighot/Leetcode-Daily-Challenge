Intuition
We perform a depth-first search from each cell containing gold, then explore all valid paths and backtrack to find the maximum gold that can be collected without revisiting cells.

Approach
Here's how the approach works:

We Iterate through the grid to find cells with gold.

For each cell with gold:

a. We perform a depth-first search (DFS) starting from that cell.

b. We mark the cell as visited to avoid revisiting before exploring it.

c. Explore all four directions (up, down, left, right) from the current cell.

d. In each direction, if the next cell is valid (within bounds, unvisited, and has gold), recursively call DFS from that cell.

e. Keep track of the maximum gold collected in the current path.

f. After exploring all paths, unmark the starting cell as visited to allow revisiting from other starting points.

Update the overall maximum gold collected if the current path's gold is greater.

Return the overall maximum gold collected from any starting cell.

Some key points are:
DFS to explore all paths from each starting cell.
Marking cells as visited to avoid revisiting.
Backtracking to explore all possible paths.
Updating the maximum gold collected at each step.
Complexity
Time complexity:O(v * 3^v), where v is the number of non- zero cells

Space complexity: O(n * m)

Code
class Solution {
public:
    vector<int> roww = {1, -1, 0, 0};
    vector<int> coll = {0, 0, -1, 1};
    int maxGold = 0;

    int dfs(vector<vector<int>>& grid, int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return 0;
        
        int curr = grid[x][y];
        grid[x][y] = 0;
        int localMaxGold = curr;

        for (int i = 0; i < 4; i++) {
            int newX = x + roww[i];
            int newY = y + coll[i];
            localMaxGold = max(localMaxGold, curr + dfs(grid, newX, newY, n, m));
        }

        grid[x][y] = curr;
        return localMaxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(grid, i, j, n, m));
                }
            }
        }

        return maxGold;
    }
};
Aproach : Optimized (Early Termination)
Optimization: The checkIfAllZeros function optimizes the solution by providing an early termination condition based on the presence of cells with zero gold, leading to improved efficiency. Before starting the backtracking process,we check if there are any cells containing only zeroes. If there are, we returns the sum of all non-zero values in the grid as it is not possible to collect any gold in this case.
Code
class Solution {
public:
    int maxGold = 0;
    vector<int> roww = {1, -1, 0, 0};
    vector<int> coll = {0, 0, -1, 1};
    int checkIfAllZeros(vector<vector<int>>& grid){
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != 0) count += grid[i][j];
                else return 0;
            }
        }

        return count;
    }

    void backtrack(vector<vector<int>>& grid, int x, int y, int count){
        if(x < 0 || x >= grid.size() || y >= grid[0].size() || y < 0) return;

        if(grid[x][y]){
            int curr = grid[x][y];
            grid[x][y] = 0;
            count += curr;

            maxGold = max(maxGold, count);

            for(int i = 0; i < 4; i++) {
                int newX = x + roww[i];
                int newY = y + coll[i];
                backtrack(grid, newX, newY, count);
            }

            grid[x][y] = curr;
        }
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int count = checkIfAllZeros(grid);
        if(count) {
            return count; 
        }
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]) {
                    backtrack(grid, i, j, 0);
                }
            }
        }

        return maxGold;
    }
};
