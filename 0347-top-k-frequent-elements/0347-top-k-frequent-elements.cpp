class Solution {
public:
struct cmp{
    bool operator()(const pair<int,int>& a,const pair<int,int>& b){
        if(a.first != b.first) return a.first>b.first;
        return a.second>b.second;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        vector<int> res;
        for(auto i:mpp){
            int ele = i.first;
            int freq = i.second;
            pair<int,int> curr = {freq,ele};
            if(pq.size()<k) pq.push(curr);
            else if(pq.top().first>curr.first) continue;
            else{
                pq.pop();
                pq.push(curr);
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};