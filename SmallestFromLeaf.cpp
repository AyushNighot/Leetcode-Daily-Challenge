Approach 🚀

Implement a DFS traversal of the tree, appending the characters corresponding to each node's value to a StringBuilder sb.
When reaching a leaf node, reverse the StringBuilder to get the path from the leaf to the root and compare it with the current smallest path found so far (ans).
If the current path is lexicographically smaller than ans, update ans to the current path.
Continue the DFS traversal for both left and right subtrees.
After processing a node, remove the last character appended to sb.
-------------------------------------------------------------------------------------------------------------------------------------------
Complexity Analysis 📊
Time complexity: O(N)O(N)O(N), where NNN is the number of nodes in the tree. We perform a DFS traversal of the entire tree.
Space complexity: O(H)O(H)O(H), where HHH is the height of the tree. The space is primarily occupied by the recursive call stack during DFS traversal.
cutecat upvote.jpg
---------------------------------------------------------------------------------------------------------------------------------------
Code
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        dfs(root, "", ans);
        return ans;
    }
    
    void dfs(TreeNode* root, string path, string& ans) {
        if (!root) return;
        
        path += char('a' + root->val);
        
        if (!root->left && !root->right) {
            reverse(path.begin(), path.end());
            if (ans.empty() || path < ans) {
                ans = path;
            }
            reverse(path.begin(), path.end());
        }
        
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }
};
