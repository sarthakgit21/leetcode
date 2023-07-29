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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return NULL;
        return fun(nums,0,n-1);
    
    }
    
    TreeNode* fun(vector<int> &nums,int left,int end){
        if(left>end) return NULL;
        int mid=(left+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=fun(nums,left,mid-1);
        root->right=fun(nums,mid+1,end);
        return root;
    }
    
};