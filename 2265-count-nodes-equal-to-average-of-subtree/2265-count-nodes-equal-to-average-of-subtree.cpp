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
    
    int findSubTreeNodes(TreeNode*root){
        if(!root) return 0;
        int val=1;        
        return val+findSubTreeNodes(root->left)+findSubTreeNodes(root->right);
        
    }
    
    int fun(TreeNode*root){
        if(!root) return 0;
        
        int left=fun(root->left);
        int right=fun(root->right);
        
        int sum=(left+right);
        int n=findSubTreeNodes(root);
        cout<<sum<<" "<<((root->val))<<" "<<n<<endl;
        if(root->val==((sum+root->val)/n)) ans++;
        return root->val+sum;
    }
    
    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return ans;
    }
};