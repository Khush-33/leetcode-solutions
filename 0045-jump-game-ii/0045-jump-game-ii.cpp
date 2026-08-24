class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps =0, endd=0,farr=0;
        for(int i=0;i<nums.size()-1;++i){
            farr = max(farr,i+nums[i]);
            if(i==endd) {
                jumps++;
                endd = farr;
            }
        }
        return jumps;
    }
};