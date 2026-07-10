class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int idx = -1, maxx_cnt = -1;
        for(int i=0;i<mat.size();i++){
            int curr = 0;
            for(int j=0;j<mat[0].size();j++){
                curr += mat[i][j];
            }
            if(curr>maxx_cnt){
                maxx_cnt = curr;
                idx = i;
            }
        }
        return {idx,maxx_cnt};
    }
};