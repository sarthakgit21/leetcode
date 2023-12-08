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
    
    
    void fun(TreeNode* root,string &s){
        if(!root) return ;
        s+=(to_string(root->val));
        // cout<<root->val;
        if(!root->left){
            if(root->right){
                s.push_back('(');
                s.push_back(')');
                s.push_back('(');
                fun(root->right,s);
                s.push_back(')');

            }
            else{
                return;
            }
        }
        else{
                s.push_back('(');
                fun(root->left,s);
                s.push_back(')');
                if(root->right){
                s.push_back('(');
                fun(root->right,s);
                s.push_back(')');
                }
        }
    }
    
    string tree2str(TreeNode* root) {
        string s;
        fun(root,s);
        return s;
    }
};