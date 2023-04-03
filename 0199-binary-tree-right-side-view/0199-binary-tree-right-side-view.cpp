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
    void fun(vector<int> &ans,int level,TreeNode* root){
        if(!root) return ;
        if(level==ans.size()) ans.push_back(root->val);
        fun(ans,level+1,root->right);
        fun(ans,level+1,root->left);
    }
    
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        fun(ans,0,root);
        return ans;
    }
};