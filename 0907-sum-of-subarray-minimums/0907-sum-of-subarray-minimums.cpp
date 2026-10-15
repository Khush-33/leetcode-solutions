class Solution {
public:
    vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> pse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;

        vector<int> next = nse(arr);
        vector<int> prev = pse(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            total = (total + left * right % mod * arr[i] % mod) % mod;
        }
        return total;
    }
};