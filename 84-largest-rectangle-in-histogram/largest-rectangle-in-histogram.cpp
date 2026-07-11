class Solution {
public:
    void prevse(vector<int>& heights, vector<int>& pse) {
        stack<int> st;
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            pse[st.top()] = -1;
            st.pop();
        }
    }
    void nextse(vector<int>& heights, vector<int>& nse) {
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            nse[st.top()] = heights.size();
            st.pop();
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse(heights.size(), -1);
        vector<int> nse(heights.size(), -1);
        int area = heights[0];
        prevse(heights, pse);
        nextse(heights, nse);
        for (int i = 0; i < heights.size(); i++) {
            area = max(area, (nse[i] - pse[i] - 1) * heights[i]);
        }
        return area;
    }
};