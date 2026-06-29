class Solution {
public:
    int check(vector<int>& nums, int ship) {
        int days = 1;
        int load = 0;

        for (int x : nums) {
            if (load + x <= ship) {
                load += x;
            } else {
                days++;
                load = x;
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(weights, mid) > days) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        };
        return left;
    }
};