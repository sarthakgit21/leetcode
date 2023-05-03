class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
    set<int> st1(nums1.begin(), nums1.end());
    set<int> st2(nums2.begin(), nums2.end());
    set_difference(st1.begin(), st1.end(), st2.begin(), st2.end(), back_inserter(ans[0]));
    set_difference(st2.begin(), st2.end(), st1.begin(), st1.end(), back_inserter(ans[1]));
    return ans;
    }
};