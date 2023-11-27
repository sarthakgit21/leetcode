
int dx[] = {2,2,1,1,-2,-2,-1,-1};
int dy[] = {1,-1,2,-2,1,-1,2,-2};
class Solution {
public:
    const int mod=1e9+7;
    
    bool isValid(int i,int j,vector<vector<int>> &phone){
        if(i<0 || j<0 ||i>=4 || j>=3 || phone[i][j]==0) return false;
        return true;
    }
    int dp[10][10][5001];
    int dfs(int i,int j,vector<vector<int>> &phone,int n){
        if(n==0) return 1;
        // int dx[8]={+2,+2,-2,-2,+1,-1,+1,-1};
        // int dy[8]={+1,-1,+1,-1,+2,+2,-2,-2};
        int ans=0;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        // cout<<i<<":"<<j<<endl;
        for(int k=0;k<8;k++){
            int Xnew=i+dx[k];
            int Ynew=j+dy[k];
            if(isValid(Xnew,Ynew,phone)){
                int val=dfs(Xnew,Ynew,phone,n-1)%mod;
                ans=(ans%mod+val)%mod;
            }
        }
        // cout<<ans<<":"<<i<<":"<<j<<endl;
        return dp[i][j][n]=ans%mod;
    }
    
    int knightDialer(int n) {
        vector<vector<int>> phone(4,vector<int> (3,1));
        // vector<vector<int>> vis(4,vector<int> (3,0));
        memset(dp,-1,sizeof dp);
        phone[3][0]=phone[3][2]=0;
        int ans=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(phone[i][j]!=0){
                    int val= dfs(i,j,phone,n-1)%mod;
                    ans=(ans%mod +val);
                    // cout<<val;
                }
                // cout<<ans<<endl;}
            }
        }
        return ans%mod;
    }
};