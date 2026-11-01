class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);
        while (left<=right){
            int mid = left+(right-left)/2;
            int day_taken = 1;
            int weights_taken = 0;
            for(int i = 0;i<n;i++){
                if (weights[i] + weights_taken <= mid){
                    weights_taken += weights[i];
                }
                else{
                    day_taken++;
                    weights_taken = weights[i];          
                }
            }
            if (day_taken <= days){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};