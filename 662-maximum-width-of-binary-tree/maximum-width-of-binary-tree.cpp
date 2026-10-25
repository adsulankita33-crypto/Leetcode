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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maximumwidth=0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        while(q.size()>0){
            int currsize=q.size();
            unsigned long long startIndex=q.front().second;
            unsigned long long endIndex=q.back().second;
            maximumwidth=max(maximumwidth,(int)(endIndex-startIndex+1));
            for(int i=0;i<currsize;i++){
                auto currNode=q.front();
                q.pop();
                if(currNode.first->left!=NULL){
                 q.push({currNode.first->left,currNode.second*2+1});
                }
                if(currNode.first->right!=NULL){
                    q.push({currNode.first->right,currNode.second*2+2});
                }
            }
        }
        return maximumwidth;
    }
};