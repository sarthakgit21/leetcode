class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> aa;
        deque<int> qt;
        for(int i=0;i<n;i++){
            if(!qt.empty()&&qt.front()==i-k) qt.pop_front();
            while(!qt.empty()&&nums[qt.back()]<nums[i]) qt.pop_back();
            qt.push_back(i);
            if(i>=k-1) aa.push_back(nums[qt.front()]);
        }
        return aa;
    }
};