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
    int height(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL){
            return height(root->right)+1;
        }
        if(root->right==NULL){
            return height(root->left)+1;
        }
        int lefttree=height(root->left);
        int righttree=height(root->right);
        int minimum=min(lefttree,righttree)+1;
        return minimum;
    }
    int minDepth(TreeNode* root) {
        return height(root);
    }
};