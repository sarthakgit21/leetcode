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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool ans=true;
        int len=0;
        while(!q.empty()){
            int sz=q.size();
            vector<int> values;
            for(int i=0;i<sz;i++){
                auto ind=q.front();
                int val=ind->val;
                q.pop();
                if(len%2==0 && val%2==0) ans=false;
                if(len%2==1 && val%2==1) ans=false;
                values.push_back(val);
                if(ind->left) q.push(ind->left);
                if(ind->right) q.push(ind->right);
            }
            for(auto x:values) cout<<x;
            cout<<endl;
            if(len%2==0){
                for(int i=1;i<values.size();i++){
                    if(values[i-1]>=values[i]) ans=false;
                }
            }
            else{
                for(int i=1;i<values.size();i++){
                if(values[i-1]<=values[i]) ans=false;
                }
            }
            cout<<ans;
            len++;
        }
        
        return ans;
    }
};