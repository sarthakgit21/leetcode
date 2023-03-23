/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark(map<TreeNode*,TreeNode*> &parents,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            // for(int i=0;i<q.size();i++){
                auto node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    parents[node->left]=node;
                }
                
                if(node->right){
                    q.push(node->right);
                    parents[node->right]=node;
                }
            // }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parents;
        mark(parents,root);
        vector<int> ans;
        // for(auto x:parents){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        queue<TreeNode*> q;
        int level=0;
        q.push(target);
        map<TreeNode*,bool> vis;
        vis[target]=true;
        while(!q.empty()){
            int sz=q.size();
          
            if(level==k){
                break;
            }
            level++;
              while(sz--){
            
            auto node=q.front();
            q.pop();
            if(node->left&&!vis[node->left]){
                q.push(node->left);
                vis[node->left]=true;
            }
            
            if(node->right&&!vis[node->right]){
                q.push(node->right);
                vis[node->right]=true;
            }
            
            if(parents[node]&&!vis[parents[node]]){
                vis[parents[node]]=true;
                q.push(parents[node]);
            }
            }
        }
        while(!q.empty()){
            // cout<<q.front()->val<<endl;
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
        
        
    }
};