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
    int countNodessleft(TreeNode* node){
        int ans=0;
        while(node){
            ans++;
            node=node->left;
        }
        return ans;
    }
    
    int countNodessright(TreeNode* node){
        int ans=0;
        while(node){
            ans++;
            node=node->right;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l=countNodessleft(root);
        int r=countNodessright(root);
        if(l==r) return (1<<r)-1;
        return 1+countNodes(root->right)+countNodes(root->left);
    }
};