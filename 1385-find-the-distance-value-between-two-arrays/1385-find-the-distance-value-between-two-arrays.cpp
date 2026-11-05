class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // sort(arr1.begin(), arr1.end());
        // sort(arr2.begin(), arr2.end());

        // int ans=0, j=0;

        // for(int x : arr1){
        //     while(j<arr2.size() && arr2[j]<x-d) j++;
        //     if(j==arr2.size() || arr2[j]>x+d) ans++;
        // }
        // return ans;
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int m=arr1.size();
        int n=arr2.size();
        int i;
        int cnt=0;
        for(i=0;i<m;i++){
            bool allValid = true;
            for(int j=0;j<n;j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    allValid=false;
                    break;
                }
            }
            if(allValid) cnt++;
        }
        return cnt;
    }
};