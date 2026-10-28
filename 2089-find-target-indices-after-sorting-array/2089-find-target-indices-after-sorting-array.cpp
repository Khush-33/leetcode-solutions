class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less=0;
        int tar=0;
        vector<int> ans;
        for(int i:nums){
            if(i<target) less++;
            else if(i==target) tar++;
        }
        for(int i=0;i<tar;i++){
            ans.push_back(i+less);
        }
        return ans;
    }
};