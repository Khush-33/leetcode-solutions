class Solution {
public:
    int countPartitions(vector<int>& a, int maxSum) {
        int partitions = 1; // at least one partition
        long subarraySum = 0; // sum of current subarray

        for (int num : a) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL); 

        // Binary search for the smallest maxSum
        while (low <= high) {
            int mid = (low + high) / 2;
            int partitions = countPartitions(nums, mid);

            if (partitions > k) {
                low = mid + 1; // too many partitions → increase maxSum
            } else {
                high = mid - 1; // valid but try smaller maxSum
            }
        }
        return low;
    }
};