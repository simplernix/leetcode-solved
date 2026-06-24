class Solution {
public:
    int binarysearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }

        int rotation = left;

        if (rotation == 0)
            return binarysearch(nums, 0, n - 1, target);

        if (target >= nums[0])
            return binarysearch(nums, 0, rotation - 1, target);
        else
            return binarysearch(nums, rotation, n - 1, target);
    }
};