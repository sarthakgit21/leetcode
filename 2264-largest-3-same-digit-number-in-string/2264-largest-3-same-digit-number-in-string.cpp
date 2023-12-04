class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        int mini=INT_MIN;
        int n=num.size();
        for(int i=0;i<n-2;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                string ss;
                ss+=num[i];
                ss+=num[i+1];
                ss+=num[i+2];
                int val=stoi(ss);
                if(val>mini){
                    mini=val;
                    ans=ss;
                }
            }
        }
        return ans;
    }
};