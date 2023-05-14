class Solution {
public:
    int gcd(int num1,int num2) {
        
        if(num2 == 0) 
            return num1;
        
        return gcd(num2,num1 % num2);

    }
    int helper(vector<int>& nums,int mask,int op,unordered_map<int,int> &mp) {
        if(mp.find(mask) != mp.end()) // checking if the combination is already computed or not ,if it is return it
            return mp[mask];

        mp[mask] = 0; // intialising the key with 0 

        // checking every possible pairs
        for(int i = 0;i < nums.size();i++) {
            for(int j = i + 1;j < nums.size();j++) {
                if(((1 << i) & mask )|| (1 << j) & mask) // checking the num at ith and jth position is not used if it is we skip the iteration
                    continue;
                
                int newMask = mask | (1 << i) | (1 << j); // now marking the ith and jth 1 which indicated that it's used

                int score = op * gcd(nums[i],nums[j]); // computing the score

                mp[mask] = max(mp[mask],score + helper(nums,newMask,op + 1,mp)); // making recursive call for the next set of combinations

            }
        }

        return mp[mask]; // return the score
    }
    int maxScore(vector<int>& nums) {
        unordered_map<int,int> mp;
        return helper(nums,0,1,mp);
    }
};