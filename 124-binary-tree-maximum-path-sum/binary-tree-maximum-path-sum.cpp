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
    int maxi=INT_MIN;
    int height(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int leftheight=max(0,height(root->left));
        int rightheight=max(0,height(root->right));
        int curr= leftheight+rightheight+root->val;
        maxi=max(maxi,leftheight+rightheight+root->val);
        return max(leftheight,rightheight)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        height(root);
        return maxi;
    }
};