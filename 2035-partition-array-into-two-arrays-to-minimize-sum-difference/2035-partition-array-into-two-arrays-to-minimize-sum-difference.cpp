class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        vector<vector<int>> L(half + 1);
        vector<vector<int>> R(half + 1);

        // Generate all subsets of left half
        for (int mask = 0; mask < (1 << half); mask++) {
            int sum = 0;
            int cnt = 0;

            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    sum += left[i];
                    cnt++;
                }
            }

            L[cnt].push_back(sum);
        }

        // Generate all subsets of right half
        for (int mask = 0; mask < (1 << half); mask++) {
            int sum = 0;
            int cnt = 0;

            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    sum += right[i];
                    cnt++;
                }
            }

            R[cnt].push_back(sum);
        }

        for (int i = 0; i <= half; i++) {
            sort(R[i].begin(), R[i].end());
        }

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        // Choose i elements from left
        // Choose half-i elements from right
        for (int i = 0; i <= half; i++) {

            int j = half - i;

            for (int sumL : L[i]) {

                // We want:
                // sumL + sumR ≈ total / 2

                double target = (double)total / 2.0 - sumL;

                auto it = lower_bound(R[j].begin(), R[j].end(), target);

                // Candidate 1
                if (it != R[j].end()) {
                    int sumR = *it;
                    int sum1 = sumL + sumR;

                    ans = min(ans, abs(total - 2 * sum1));
                }

                // Candidate 2
                if (it != R[j].begin()) {
                    --it;

                    int sumR = *it;
                    int sum1 = sumL + sumR;

                    ans = min(ans, abs(total - 2 * sum1));
                }
            }
        }

        return ans;
    }
};