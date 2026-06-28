class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        nums[0]=1;
        for(int i=1;i<n;i++){
            if (nums[i]-nums[i-1]<=1){

            }else{
                nums[i]=nums[i-1]+1;
                };
        }
        return nums[n-1];

    }
};