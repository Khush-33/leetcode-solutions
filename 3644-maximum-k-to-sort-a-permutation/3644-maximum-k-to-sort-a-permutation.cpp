class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = (1<<21)-1;
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            if(i!=nums[i]){
                ans = ans&nums[i];
                flag=false;
            }
        }
        if(flag) return 0;
        return ans;
    }
};