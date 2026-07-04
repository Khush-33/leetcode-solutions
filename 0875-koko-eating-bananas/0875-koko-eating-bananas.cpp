class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>maxi) maxi = piles[i];
        }
        return maxi;
    }
    double totalHr(vector<int>& piles, int hrs){
        double total = 0;
        for(int i=0;i<piles.size();i++){
            total += ceil((double)piles[i]/(double)hrs);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while(low<=high){
            int mid = low + (high-low)/2;
            double totalHrs = totalHr(piles,mid);
            if(totalHrs <= h) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};