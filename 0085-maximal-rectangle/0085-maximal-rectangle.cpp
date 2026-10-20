class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = 0;
                if(!st.empty()) pse = st.top();
                else pse = -1;
                maxArea = max(maxArea, heights[element]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = 0;
            if(!st.empty()) pse = st.top();
            else pse = -1;
            maxArea = max(maxArea, heights[element]*(nse-pse-1)); 
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> heights(cols,0);
        int maxArea=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            maxArea = max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }
};