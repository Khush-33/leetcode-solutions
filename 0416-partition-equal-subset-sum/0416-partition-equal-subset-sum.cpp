class Solution {
public:
    bool f(int n, int k, vector<int> &arr){
        vector<bool> prev(k+1,0), curr(k+1,0);
        prev[0] = curr[0] = true;
        if(arr[0] <= k) prev[arr[0]] = true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[i]<=target) take = prev[target-arr[i]];
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int tSum = 0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            tSum += nums[i];
        }
        if(tSum%2) return false;
        int target = tSum/2;

        return f(n, target, nums);
    }
};