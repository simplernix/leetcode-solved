class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0]=1;
        int mx=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]<=1){
                mx=arr[i];
            }
            else{
                mx=mx+1;
                arr[i]=mx;

            }

        }
        return mx;
    }
};