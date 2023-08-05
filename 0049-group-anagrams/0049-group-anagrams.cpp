class Solution {
public:
string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();
        if(n==0) return ans;
        unordered_map<string,vector<string>> mp;
        for(auto x:strs)
        {
            mp[strSort(x)].push_back(x);
        }
        for(auto x:mp) ans.push_back(x.second);
        return ans;
    }
};