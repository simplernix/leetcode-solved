class Solution {
public:
    int upper(int x, int y){

        if (x<y){
            return 1;
        }
        else if (x%y>0){
            return (x/y)+1;
        }
        else{
            return x/y;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int n = piles.size();
        long long hours_taken=0;
        int min_speed=right;
        int speed = 0;
        while(left<=right){
            speed = left+(right-left)/2;
            hours_taken=0;
            for (int i=0; i<n;i++){
                hours_taken += upper(piles[i],speed);
            }
            if (hours_taken<=h){
                min_speed=min(speed,min_speed) ;
                right=speed-1;
            }
            else{
                left=speed+1;
            };
            
        };
        return min_speed;
    }
}
;