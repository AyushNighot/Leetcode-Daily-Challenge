🧠 Thinking Behind the Solution:
To solve this problem, we can use Depth-First Search (DFS) traversal of the binary tree. As we traverse from the root to each leaf node, we maintain a path_sum variable which accumulates the number formed by the nodes visited so far...

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


✅Approach:
To solve the problem of finding the sum of numbers represented by root-to-leaf paths in a binary tree using a Depth-First Search (DFS) approach, we can follow these steps:-

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Use DFS Algorithm:

Implement a DFS traversal of the binary tree, starting from the root.
Maintain a variable to keep track of the current number formed from the root to the current node as you traverse.
DFS Recursive Function:

Define a recursive function (dfs function) that takes the current node, the current path value, and a variable to accumulate the sum of all root-to-leaf path numbers.
If the current node is None, return immediately (base case for leaf nodes).
Update the current path value by appending the current node's value (e.g., path_sum = path_sum * 10 + node.val).
If the current node is a leaf node (i.e., it has no children), add the path_sum to the sum.
Recursively call the function for the left and right children of the current node, passing the updated path_sum.
Initialize and Call the DFS Function:

Start the DFS traversal from the root node with an initial path of 0.
Accumulate the sum of all root-to-leaf path numbers using the DFS function.
Return the Result:

After the DFS traversal completes, return the accumulated sum, which represents the total sum of all root-to-leaf path numbers in the binary tree.
Let's walkthrough🚶🏻‍♂️ the implementation process with an example for better understanding🎯:
Let's walkthrough the execution for a sample binary tree:

        1
       / \
      2   3
Initial Call: sumNumbers(root)

root: Node with value 1
path_sum: 0
Execution:

dfs(1, 0) → dfs(2, 1) (left child)
dfs(2, 10) → dfs(None, 12) (left child is None, return 12)
dfs(1, 0) → dfs(3, 1) (right child)
dfs(3, 10) → dfs(None, 13) (left child is None, return 13)
Final Result: 12 + 13 = 25


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Code👩🏻‍💻:-


class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* node, int pathSum) {
        if (!node)
            return 0;
        
        pathSum = pathSum * 10 + node->val;
        
        if (!node->left && !node->right)
            return pathSum;
        
        return dfs(node->left, pathSum) + dfs(node->right, pathSum);
    }
};
