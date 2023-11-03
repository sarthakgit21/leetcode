class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int initialVal=1;
        vector<string> ans;
        string push="Push";
        string pop="Pop";
        for(auto x:target)
        {
            if(x==initialVal)
            {
                ans.push_back(push);
            }
            else
            {
                while(initialVal<x){
                ans.push_back(push);
                ans.push_back(pop);
                initialVal++;}
                ans.push_back(push);
            }
            initialVal++;
        }
        return ans;
    }
};