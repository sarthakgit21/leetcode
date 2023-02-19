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
//     TreeNode*fun(vector<int>& preorder, vector<int>& inorder,int prestart,int preend,int instart,int inend,map<int,int>mp){
//         if(preend<prestart||inend<instart) return NULL;
//         TreeNode*node=new TreeNode(preorder[prestart]);
//         int inroot=mp[node->val];
//         int leftover=inroot-instart;
//         node->left=fun(preorder,inorder,prestart+1,prestart+leftover,instart,inroot-1,mp);
//         node->right=fun(preorder,inorder,prestart+leftover+1,preend,inroot+1,inend,mp);
//         return node;
//     }
    
    
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         map<int,int> mp;
//         int i=0;
//         for(auto x:inorder){
//             mp[x]=(i++);
//         }
//         TreeNode* root=fun(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mp);
//         return root;
//     }
       TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode *root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd, map<int,int> &mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        
        int inRoot = mp[root->val];
        int numsleft = inRoot - inStart;
        
        root->left =buildTree(preorder,preStart+1,preStart+numsleft,inorder,inStart,inRoot-1,mp);
        root->right =buildTree(preorder,preStart+numsleft+1,preEnd,inorder,inRoot+1,inEnd,mp);
        return root;
    }
};