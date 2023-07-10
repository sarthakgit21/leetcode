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
    int ansval;
        int fun(TreeNode *root)
        {
            if (root == NULL) return 0;
            int left =minDepth(root->left);
            int right = minDepth(root->right);
            // ansval=min(ansval,1+min(left,right));
            if(left==0&&right==0) return 1;
            if(left==0||right==0) return 1+max(left,right);

            return 1+min(left, right);
        }

    int minDepth(TreeNode *root)
    {
        int ans = fun(root);
        return ans;
    }
};