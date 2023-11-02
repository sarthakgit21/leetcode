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
    unordered_map<TreeNode*,int> mp;
    int findSubTreeNodes(TreeNode*root){
        if(!root) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];
        int val=1;        
        return mp[root]=val+findSubTreeNodes(root->left)+findSubTreeNodes(root->right);
        
    }
    
    int fun(TreeNode*root){
        if(!root) return 0;
        
        int left=fun(root->left);
        int right=fun(root->right);
        
        int sum=(left+right);
        int n=findSubTreeNodes(root);
        if(root->val==((sum+root->val)/n)) ans++;
        return root->val+sum;
    }
    
    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return ans;
    }
};