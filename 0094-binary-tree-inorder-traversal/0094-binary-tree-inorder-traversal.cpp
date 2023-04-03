/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> ans;

    vector<int> inorderTraversal(TreeNode *root) {
        while(root){
            if(!root->left){
                ans.push_back(root->val);
                root=root->right;
            }
            else{
                TreeNode* cur=root->left;
                while(cur->right && cur->right!=root) cur=cur->right;
                if(cur->right==NULL){
                    cur->right=root;
                    root=root->left;
                }
                else{
                    ans.push_back(root->val);
                    cur->right=NULL;
                    root=root->right;
                    
                }
            }
        }
        return ans;
    }
};