class Solution {
public:
    int upper(int n, int g) {
        if (n % g == 0) {
            return n / g;
        } else {
            return (n / g) + 1;
        }
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int left = 1;
        int right = maxi;
        while (left <= right) {
            int mid=left+(right-left)/2;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += upper(nums[i], mid);
            }
            if (sum > threshold) {
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return left;
    }
};