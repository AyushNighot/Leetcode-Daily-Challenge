/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);

        return diameter;
    }
private:
    int height(TreeNode* node , int &daimeter)
    {
        int maxi = 0;
        if (node == NULL)
        {
            return 0;
        }

        int l = height(node -> left,daimeter);
        int r = height( node -> right,daimeter);
        daimeter = max(daimeter,l + r);

        return 1+ max(l,r);
    }
};
