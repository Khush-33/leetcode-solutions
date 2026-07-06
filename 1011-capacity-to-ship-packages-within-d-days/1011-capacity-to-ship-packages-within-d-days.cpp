class Solution {
public:
    // int summ(vector<int>& weights){
    //     int sum = 0;
    //     for(int i=0;i<weights.size();i++) sum += weights[i];
    //     return sum;
    // }
    // int maxx(vector<int>& weights){
    //     int maxi = INT_MIN;
    //     for(int i=0;i<weights.size();i++) maxi = max(maxi,weights[i]);
    //     return maxi;
    // }
    int capacity(vector<int>& weights, int mid){
        int days = 1, load = 0;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i]>mid){
                days++;
                load = weights[i];
            }
            else load += weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<=high){
            int mid = low+(high-low)/2;
            if(capacity(weights,mid)<=days) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};