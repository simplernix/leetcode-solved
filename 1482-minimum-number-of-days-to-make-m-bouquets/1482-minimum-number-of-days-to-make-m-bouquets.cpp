class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int flower) {
        
        int left=1;
        int right = *max_element(bloomDay.begin(),bloomDay.end());
        int n = bloomDay.size();
        if ((long long)m * flower > n) {
            return -1;
        }
        int bq=0;
        int k=0;
        int min_days=INT_MAX;


        while(left<=right){
            int day = left+(right-left)/2;
            bq=0;
            k=0;
            for(int i=0;i<n;i++){
                if (bloomDay[i]<=day){
                    k++;
                    if (k == flower){
                        bq++;
                        k=0;
                    }
                }
                else{
                    k=0;
                };
            };
            if (bq>=m){
                min_days=min(min_days,day);
                right=day-1;
            }
            else{
                left=day+1;
            }

        };
        return min_days;

    }
};