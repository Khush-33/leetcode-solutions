
class Solution {
public:
    multiset<int> small, large;
    long long sumL = 0, sumR = 0;

    // Dono multisets ka size balance karna
    void balance() {
        while (small.size() > large.size() + 1) {
            int val = *small.rbegin();

            small.erase(small.find(val));
            large.insert(val);

            sumL -= val;
            sumR += val;
        }

        while (small.size() < large.size()) {
            int val = *large.begin();

            large.erase(large.find(val));
            small.insert(val);

            sumR -= val;
            sumL += val;
        }
    }

    // Naya element window mein add karna
    void add(int val) {
        if (small.empty() || val <= *small.rbegin()) {
            small.insert(val);
            sumL += val;
        } else {
            large.insert(val);
            sumR += val;
        }

        balance();
    }

    // Window se element remove karna
    void remove(int val) {
        auto it = small.find(val);

        if (it != small.end()) {
            small.erase(it);
            sumL -= val;
        } else {
            it = large.find(val);

            large.erase(it);
            sumR -= val;
        }

        balance();
    }

    // Current window ka minimum cost calculate karna
    long long getCost() {
        long long median = *small.rbegin();

        // Median se chhote elements ko equal karne ka cost
        long long leftCost = median * small.size() - sumL;

        // Median se bade elements ko equal karne ka cost
        long long rightCost = sumR - median * large.size();

        return leftCost + rightCost;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Har window ka cost store karenge
        vector<long long> cost(n - x + 1);

        // Pehli window ke elements add karo
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        // Sliding window se baaki costs calculate karo
        for (int i = x; i < n; i++) {
            remove(nums[i - x]); // Purana element remove
            add(nums[i]);        // Naya element add

            cost[i - x + 1] = getCost();
        }

        // DP: dp[t][i] = first i elements se exactly t
        // non-overlapping windows select karne ka minimum cost
        const long long INF = 1e18;

        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));

        // Zero windows select karne ka cost zero hai
        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int t = 0; t <= k; t++) {

                // Agar current state possible nahi hai toh skip
                if (dp[t][i] == INF) {
                    continue;
                }

                // Choice 1: Current index ko skip karo
                dp[t][i + 1] = min(dp[t][i + 1], dp[t][i]);

                // Choice 2: Current index se window select karo
                if (t < k && i + x <= n) {

                    // Current window ka cost add karo
                    long long newCost = dp[t][i] + cost[i];

                    // x positions jump karo taaki overlap na ho
                    dp[t + 1][i + x] = min(dp[t + 1][i + x], newCost);
                }
            }
        }

        // Exactly k windows select karne ka minimum cost
        return dp[k][n];
    }
};
