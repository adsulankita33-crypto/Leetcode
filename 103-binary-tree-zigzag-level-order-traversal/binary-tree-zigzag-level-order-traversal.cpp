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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*>currlevel;
        stack<TreeNode*>nextlevel;
        bool lefttoright=true;
        vector<int>level;
        currlevel.push(root);
        while(!currlevel.empty()){
            TreeNode*temp=currlevel.top();
            currlevel.pop();
            level.push_back(temp->val);
            if(lefttoright==true){
              if(temp->left!=NULL){
                nextlevel.push(temp->left);
              }
              if(temp->right!=NULL){
                nextlevel.push(temp->right);
              }
            }
            else{
                if(temp->right!=NULL){
                    nextlevel.push(temp->right);
                }
                if(temp->left!=NULL){
                    nextlevel.push(temp->left);
                }
            }
            if (currlevel.empty()) {
                ans.push_back(level);
                level.clear();

                lefttoright = !lefttoright;
                swap(currlevel, nextlevel);
            } 
        }
        return ans;
    }
};