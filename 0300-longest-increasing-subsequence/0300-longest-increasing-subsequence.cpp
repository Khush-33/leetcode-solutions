class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (int x : nums) {
            int i = lower_bound(tails.begin(), tails.end(), x) - tails.begin();
            
            if (i == tails.size())
                tails.push_back(x);
            else
                tails[i] = x;
        }

        return tails.size();
    }
};