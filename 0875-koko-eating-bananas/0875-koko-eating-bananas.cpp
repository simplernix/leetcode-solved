class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        long long hours_taken = 0;
        int hours = INT_MAX;
        int n = piles.size();
        while (left<right){
            int speed=left+(right-left)/2;
            int hours_taken=0;
            for (int j=0;j<n;j++){
                hours_taken+= (piles[j]+speed-1)/speed;
            }
            if (hours_taken<=h){
                right=speed;
            }
            else{
                left=speed+1;
            }
        }
        return left;
    }
}
;