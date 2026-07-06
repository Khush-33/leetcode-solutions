class Solution {
public:
    int maxel(vector<int>& nums){
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++) maxi = max(maxi,nums[i]);
        return maxi;
    }
    int possible(vector<int>& nums, int mid){
        int newSum = 0;
        for(int i=0;i<nums.size();i++){
            newSum += ceil((double)nums[i]/(double)mid);
        }
        return newSum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = maxel(nums);
        while(low<=high){
            int mid = low +(high-low)/2;
            if(possible(nums,mid)<=threshold) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};