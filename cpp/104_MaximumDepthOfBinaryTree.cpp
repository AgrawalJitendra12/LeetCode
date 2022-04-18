/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){return 0;}
        int left = 0;
        int right = 0;
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        if(root->left!=NULL){
            left = 1 + maxDepth(root->left);
        }
        if(root->right!=NULL){
            right = 1 + maxDepth(root->right);
        }
        if(right>left){
            return right;
        }
        return left;
    }
};