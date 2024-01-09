Problem Link:- https://leetcode.com/problems/leaf-similar-trees

///////////////////////////////////////////////////////////////////////////////////////////////

Intuition
The intuition behind the approach is that the code focuses on the values of leaf nodes during traversal, ignoring the internal nodes. By comparing the sequences of leaf values, the code determines if the two trees have similar leaf structures.

////////////////////////////////////////////////////////////////////////////////////////////////

Approach
The approach taken in the provided code involves performing an in-order traversal on both binary trees (root1 and root2). During the traversal, the code checks if a node is a leaf node (i.e., it has no left or right child). If a leaf node is encountered, its value is added to a list (v1 for the first tree and v2 for the second tree).

////////////////////////////////////////////////////////////////////////////////////////////////

Complexity

Time complexity:
The time complexity is O(N), where N is the total number of nodes in both trees. This is because we visit each node once during the in-order traversal

Space complexity:
The space complexity is O(H), where H is the height of the tree, due to the recursive nature of the in-order traversal. In the worst case (skewed tree), H could be equal to N, making the space complexity O(N).

//////////////////////////////////////////////////////////////////////////////////////////////////

Code:-

class Solution {
public:
void inorder(TreeNode* root, vector<int> &v)
    {
        if(root!=NULL)
        {
            inorder(root->left, v);
            if(root->left == NULL && root->right == NULL)
            {
                v.push_back(root->val);
            }
            inorder(root->right,v);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> v,v1;
        inorder(root1,v);
        inorder(root2,v1);
        return v==v1;
    }
};