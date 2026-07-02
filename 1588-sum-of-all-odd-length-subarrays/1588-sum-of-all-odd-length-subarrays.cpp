class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            int curr_sum = 0;
            for(int j=i;j<arr.size();j++){
                curr_sum += arr[j];
                if((j-i+1)%2 == 1) sum += curr_sum;
            }
        }
        return sum;
    }
};