/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> verticalTraversal(TreeNode *root)
        {
            map<int, map<int, vector< int>>> mp;
            vector<vector < int>> ans;
            if (!root) return ans;
            queue<pair<TreeNode*, pair<int, int>>> q;
            q.push({ root,
                { 0,
                    0 } });
           	// mp[0].push_back(root->val);
            while (!q.empty())
            {
                int sz = q.size();
                while (sz--)
                {
                    auto it = q.front().first;
                    int x = q.front().second.first;
                    int y = q.front().second.second;
                    q.pop();
                    mp[x][y].push_back(it->val);
                    if (it->left) q.push({ it->left,
                        {
                            x - 1,
                            y + 1
                        } });
                    if (it->right) q.push({ it->right,
                        {
                            x + 1,
                            y + 1
                        } });
                }
            }
            for (auto x: mp)
            {
                vector<int> v;
                for (auto xx: x.second)
                {
                    vector<int> vv(xx.second);
                    sort(vv.begin(), vv.end());
                    for (auto xxx:vv)
                    {
                        v.push_back(xxx);
                    }
                }
                // sort(v.begin(), v.end());
                ans.push_back(v);
            }
            return ans;
        }
};