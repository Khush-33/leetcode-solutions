class Solution {
public:

    bool check(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1)
            return false;

        int i = 0;
        int j = 0;

        while (i < s1.size()) {

            if (j < s2.size() && s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }

        return j == s2.size();
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(),
            [](string &a, string &b) {
                return a.size() < b.size();
            });

        int n = words.size();

        vector<int> dp(n, 1);

        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int prev = 0; prev < i; prev++) {

                if (check(words[i], words[prev])) {
                    dp[i] = max(dp[i], dp[prev] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};