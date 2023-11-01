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
    int maxi=0;
    unordered_map<int,int> mp;
    
    void fun(TreeNode*root){
        if(!root) return;
        mp[root->val]++;
        maxi=max(maxi,mp[root->val]);
        if(root->left)fun(root->left);
        if(root->right)fun(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        fun(root);
        
        vector<int> ans;
        for(auto [x,y]:mp) if(y==maxi) ans.push_back(x);
        return ans;
    }
};