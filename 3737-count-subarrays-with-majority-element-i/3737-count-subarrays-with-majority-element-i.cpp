class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        for (int left = 0; left < n; left++) {
            int t_count = 0;
            for (int right = left; right < n; right++) {
                if (nums[right] == target) {
                    t_count++;
                }
                int len = right - left + 1;
                if (t_count > len / 2) {
                    ans++;
                }
            }
        };
        return ans;
    }
};