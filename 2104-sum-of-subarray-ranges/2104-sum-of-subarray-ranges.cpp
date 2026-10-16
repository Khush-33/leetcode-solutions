class Solution {
public:
    vector<int>findnse(vector<int>&arr){
        int n=arr.size();
        vector<int>nse(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]>=arr[i])
        st.pop();
        nse[i]=st.empty()?n:st.top();
        st.push(i);
        }
        return nse;
    }
       vector<int>findpse(vector<int>&arr){
        int n=arr.size();
        vector<int>pse(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()]>arr[i])
        st.pop();
        pse[i]=st.empty()?-1:st.top();
        st.push(i);
        }
        return pse;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int>nse=findnse(arr);
        vector<int> pse=findpse(arr);
        int mod=(1e9+7);
        long long left,right;
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            left=i-pse[i];
            right=nse[i]-i;
            sum+=1LL*arr[i]*left*right;
        }
        return sum;
    }
        vector<int>findnge(vector<int>&arr){
        int n=arr.size();
        vector<int>nge(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]<=arr[i])
        st.pop();
        nge[i]=st.empty()?n:st.top();
        st.push(i);
        }
        return nge;
    }
       vector<int>findpge(vector<int>&arr){
        int n=arr.size();
        vector<int>pge(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()]<arr[i])
        st.pop();
        pge[i]=st.empty()?-1:st.top();
        st.push(i);
        }
        return pge;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int>nge=findnge(arr);
        vector<int> pge=findpge(arr);
        int mod=(1e9+7);
        long long left,right;
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            left=i-pge[i];
            right=nge[i]-i;
            sum+=1LL*arr[i]*left*right;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};