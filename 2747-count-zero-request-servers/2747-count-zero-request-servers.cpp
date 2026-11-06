class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
        auto lambda = [](vector<int>& vec1, vector<int>& vec2){
            return vec1[1]<vec2[1]; // sort on basis of time in ascending order
        };
        sort(begin(logs), end(logs), lambda);
        int q=queries.size();
        vector<int> res(q);
        vector<pair<int,int>> timee(q);
        for(int i=0;i<q;i++){
            timee[i] = {queries[i],i};
        }
        sort(timee.begin(), timee.end());
        unordered_map<int,int> mpp;
        int i=0;
        int j=0;
        for(auto [time, idx] : timee){
            int st = time-x;
            int end = time;
            while(j<m && logs[j][1]<=end){
                mpp[logs[j][0]]++;
                j++;
            }
            while(i<m && logs[i][1]<st){
                mpp[logs[i][0]]--;
                if(mpp[logs[i][0]] ==0) mpp.erase(logs[i][0]);
                i++;
            }
            res[idx] = n-mpp.size();
        }
        return res;
    }
};