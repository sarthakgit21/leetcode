class Solution {
public:
    
    bool possible(vector<int>& dist, double hour,int mid){
        
        double noOfHours=0;
        
        for(int i=0;i<dist.size()-1;i++)
        {
            noOfHours+=ceil((dist[i]/(double)mid));
        }
        noOfHours+=(dist[dist.size()-1]/(double)mid);
        
        return noOfHours<=hour;
        
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans=-1;
        
        int low=1;
        int high=1e7;
        while(low<=high){
            
            int mid=low+(high-low)/2;
            if(possible(dist,hour,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
            
        }
        
        return ans;
        
    }
};