class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<pair<int,int>> vp;
        int n=speed.size();
        for(int i=0;i<n;i++){
            double num=ceil((double)dist[i]/(double)speed[i]);
            vp.push_back({num,speed[i]});
        }
        sort(vp.begin(),vp.end());
        int ans=0;
        int time=0;
        for(auto x:vp) cout<<x.first<<endl;
        // cout<<n<<endl;
        for(int i=0;i<n;i++){
            int dis=vp[i].first;
            int speed=vp[i].second;;
            if(dis>time){
                ans++;
            }
            else{
                break;
            }
            time+=1;
        }
        return ans;
    }
};