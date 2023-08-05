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
    vector<TreeNode*> findAllBST(int ind,int end)
    {
        
        if(ind>end)
        {
            return {NULL};
        }
        vector<TreeNode*> val;
        for(int i=ind;i<=end;i++)
        {
            auto left=findAllBST(ind,i-1);
            auto right=findAllBST(i+1,end);
            for(auto it:left)
            {
                for(auto pt:right)
                {
                    TreeNode* temp=new TreeNode(i);
                    temp->left=it;
                    temp->right=pt;
                    val.push_back(temp);
                }
            }
        }
        
        
        return val;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n==0) return ans;
        return findAllBST(1,n);
    }
};