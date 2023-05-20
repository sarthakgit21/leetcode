class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s1=0;
        int s2=0;
        for(auto x:gas) s1+=x;
        for(auto x:cost) s2+=x;
        if(s1<s2) return -1;
        int c=0;
        int ans=0;
        for(int i=0;i<cost.size();i++){
            c+=(gas[i]-cost[i]);
            if(c<0){
                ans=i+1;
                c=0;
            }
        }
        return ans;
    }
};