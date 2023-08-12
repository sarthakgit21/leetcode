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
    int ans=0;
    vector<int> helper(TreeNode*root,int d)
    {
        if(!root) return {0};
        if(root->left==NULL and root->right==NULL) return {1};
        
        auto l=helper(root->left,d);
        
        auto r=helper(root->right,d);
        
        for(auto a:l){
            for(auto b:r)
            {
                if((a&&b)&&a+b<=d) ans++;
            }
        }
        
        vector<int>pr;
        for(auto a:l)  if(a&&a+1<d) pr.push_back(a+1);
        for(auto a:r)  if(a&&a+1<d) pr.push_back(a+1);
        return pr;
        
        
    }
    
    int countPairs(TreeNode* root, int distance) {
        helper(root,distance);
        return ans;
    }
};