class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        int l=0, r=n-1;
        int leftMax = 0, rightMax=0;
        int total=0;
        while(l<r){
            if(heights[l]<=heights[r]){
                if(leftMax > heights[l]){
                    total += leftMax - heights[l];
                }
                else{
                    leftMax = heights[l];
                }
                l++;
            }
            else{
                if(rightMax>heights[r]){
                    total += rightMax - heights[r];
                }
                else{
                    rightMax = heights[r];
                }
                r--;
            }
        }
        return total;
    }
};