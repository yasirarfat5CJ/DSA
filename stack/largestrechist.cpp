class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>right(n,0);
        vector<int>left(n,0);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            right[i]= s.empty()?n:s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
         for(int i=0;i<n;i++){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            left[i]= s.empty()?-1:s.top();
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
           int width = right[i] - left[i] - 1;
            int area = heights[i] * width; 
            ans = max(ans, area);
        }
        return ans;
    }
};

/*in this problem we have to find the largest rectangle in histogram
approach:the formula if rectangle we apply that is height* width
to calculate the width we apply the  concept of nextsamller and prevsmaller element similar to what we did to next greater ele
one we width is find we travese on th original arr for every element we calculate area and track the max area using max function
*/