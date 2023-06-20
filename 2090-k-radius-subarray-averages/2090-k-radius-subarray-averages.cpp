class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<long> prefsum(nums.size(), 0);
        long sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            prefsum[i] = sum;
        }
        vector<int> res(nums.size());

        for (int i=0; i<nums.size(); i++) {
            if (i < k || i >= nums.size() - k)
                res[i] = -1;
            else {
                res[i] = (prefsum[i+k] - prefsum[i-k] + nums[i-k]) / (2 * k + 1);
            }
        }
        return res ;
    }
};