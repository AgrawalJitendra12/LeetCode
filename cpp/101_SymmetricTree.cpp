// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool isSymmetric(TreeNode* root) {
        if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)){
            return false;
        }
        return checkSides(root->left, root->right);
    }
    bool checkSides(TreeNode* root1, TreeNode* root2){
        if (!root1 && !root2) {
            return true;
        } else if (!root1 || !root2) {
            return false;
        }
        
        if(root1->val != root2->val){
            return false;
        }
        return checkSides(root1->left, root2->right) && checkSides(root1->right, root2->left);
    }
};