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
    
   TreeNode* build(vector<int>&inorder, vector<int>&postorder, int is, int ie, int ps, int pe, unordered_map < int, int > &mp){
        if((ps > pe) || (is > ie))
            return NULL;
        
        int ind = mp[postorder[pe]];
        int nelem = ind - is;

        TreeNode* root = new TreeNode(postorder[pe]);
        root->left =  build(inorder, postorder,    is,  ind - 1, ps, ps + nelem - 1, mp);
        root->right = build(inorder, postorder, ind+1,  ie, ps + nelem, pe-1, mp);
        return root;
    }
   
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postLen = postorder.size();
        int inLen = inorder.size();
        if(postLen != inLen)
            return NULL;

        unordered_map < int, int > mp;

        for(int i = 0; i < inLen; i++)
            mp[inorder[i]] = i;

        return build(inorder, postorder, 0, inLen - 1, 0, postLen - 1, mp);
    }
};