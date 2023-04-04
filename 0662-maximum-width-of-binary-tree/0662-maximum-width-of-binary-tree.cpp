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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
                int sz=q.size();
                int v=q.front().second;
            int f,l;
                for(int i=0;i<sz;i++){
                    auto it=q.front();
                    int val=it.second-v;
                    q.pop();
                    if(i==0) f=val;
                    if(i==sz-1) l=val;
                    if(it.first->left){
                        q.push({it.first->left,(long long)val*2+1});
                    }
                    if(it.first->right){
                        q.push({it.first->right,(long long)val*2+2});
                    }
                }
                ans=max(ans,l-f+1);
            }
        
        return ans;
    }
};