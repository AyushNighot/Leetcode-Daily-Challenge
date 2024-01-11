Problem Link:- https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

///////////////////////////////////////////////////////////////////////////////////////////////

Problem Description:
Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

/////////////////////////////////////////////////////////////////////////////////////////////

Approach:
Defines two functions:

maxAncestorDiff:

This is the main function that serves as an entry point.
It initializes the traversal by calling the helper function with the root of the tree and initial minimum and maximum values set to the root's value.
Returns the result obtained from the helper function.

helper:

This is the recursive helper function that performs the actual traversal.
Takes three parameters: the current node r, the current minimum value mn, and the current maximum value mx.
If the current node is nullptr (i.e., a null node), it means we have reached the end of a branch. The function returns the difference between the maximum and minimum values encountered along the path.
Updates the mn and mx values based on the current node's value.
Recursively calls itself for the left and right subtrees with the updated mn and mx values.
Returns the maximum difference between the left and right subtrees.
Explanation:
Initialization:

The maxAncestorDiff function is initially called with the root node of the binary tree.
The helper function is called with the root's value, serving as the initial minimum (mn) and maximum (mx) values.
Traversal:

The helper function recursively traverses the binary tree, updating the minimum and maximum values along the path.
Calculation:

At each node, it calculates the maximum difference between the current node's value and the minimum or maximum value encountered along the path.
Result:

The result is the maximum difference between any two nodes in the binary tree.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

Time Complexity-O(N)

CODE :-

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }

    int helper(TreeNode* r, int mn, int mx) {
        if (r == nullptr) {
            return mx - mn;
        }
		  // Update min and max based on the current node's value
        mn = min(mn, r->val);
        mx = max(mx, r->val);
		// Recursively calculate the max difference for left and right subtrees
        int leftDiff = helper(r->left, mn, mx);
        int rightDiff = helper(r->right, mn, mx);
		 // Return the maximum difference between left and right subtrees
        return max(leftDiff, rightDiff);
    }
};