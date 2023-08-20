class Solution {
public:
    int dp[301][11];
    int minDiff(vector<int>& jobs, int d,int i)
    {
        int n=jobs.size();
        
        if(d==1)
        {
            return dp[i][d]=*max_element(jobs.begin()+i,jobs.end());
        }
        if(dp[i][d]!=-1) return dp[i][d];
        int mini=INT_MAX;
        int maxi=jobs[i];
        for(int ind=i;ind<=n-d;ind++)
        {
            maxi=max(maxi,jobs[ind]);
            int val=maxi+minDiff(jobs,d-1,ind+1);
            mini=min(mini,val);
        }
        return dp[i][d]=mini;
        
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d>jobDifficulty.size()) return -1;
        memset(dp,-1,sizeof(dp));
        return minDiff(jobDifficulty,d,0);
    }
};