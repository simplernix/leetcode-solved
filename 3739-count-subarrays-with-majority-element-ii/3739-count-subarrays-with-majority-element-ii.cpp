class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if (nums[i]==target){
                nums[i]=1;
            }
            else{ nums[i]=-1;}
        }
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int shift=n;
        vector<int> freq(2*n+1,0);
        long long valid=0;
        int lastsum=0;
        freq[shift]=1;
        long long cnt=0;
        for(int i=0;i<n;i++){
            if (prefix[i]>lastsum){
                valid+=freq[lastsum+shift];
            }else{
                valid-=freq[prefix[i]+shift];
            }
            cnt+=valid;
            freq[prefix[i]+shift]++;
            lastsum=prefix[i];
                    }
                    return cnt;


        }
};