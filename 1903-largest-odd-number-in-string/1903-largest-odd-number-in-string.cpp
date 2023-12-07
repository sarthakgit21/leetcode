class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        int ind=-1;
        for(int i=0;i<num.size();i++){
            if((num[i]-'0')&1) ind=i;
        }
        if(ind==-1) return ans;
        ans=num.substr(0,ind+1);
        return ans;
    }
};