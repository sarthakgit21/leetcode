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
    void fun(vector<int> &nodes,TreeNode* root){
        if(!root) return ; 
        nodes.push_back(root->val);
        fun(nodes,root->left);
        fun(nodes,root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        fun(nodes,root);
        return nodes;
    }
};