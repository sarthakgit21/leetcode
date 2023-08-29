class Solution {
public:
    int bestClosingTime(string customers) {
        int ans=0;
        int ind=-1;
        int n=customers.size();
        int score=0;
        for(int i=0;i<n;i++)
        {
            if(customers[i]=='Y') score++;
            else score--;
            if(score>ans)
            {
                ans=score;
                ind=i;
            }
            
        }
        
        return ind+1;
    }
};