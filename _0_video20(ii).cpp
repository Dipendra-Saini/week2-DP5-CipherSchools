#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    stack<int> st;

    for(int i = 0; i <= n; i++){
        int currHeight = i == n ? 0 : heights[i];
        while(!st.empty() && currHeight < heights[st.top()]){
            int top = st.top(); st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            int area = heights[top] * width;
            maxArea = max(area, maxArea);
        }
        st.push(i);
    }
    return maxArea;
}

int main(){

    vector<int> height = {2,1,5,6,2,3};
    int result = largestRectangleArea(height);
    cout<<result<<endl;

    return 0;
}