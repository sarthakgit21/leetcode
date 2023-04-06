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
        void fun(vector<TreeNode*> &v, TreeNode *root)
        {
            if (!root) return;
            v.push_back(root);
            fun(v, root->left);
            fun(v, root->right);
        }
    void flatten(TreeNode *root)
    {
        vector<TreeNode*> v;
        fun(v, root);
        if(v.size()==1) return;

        for (int i = 0; i < v.size(); i++)
        {
            root->left = NULL;
            root->right = v[i];
            // if (i != (v.size() - 1))
                root = root->right;
        }
    }
};