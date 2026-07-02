class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i = 0;
        while (i < tokens.size()) {
            if (tokens[i].length() == 1 &&
                (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                 tokens[i] == "/")) {
                int temp2 = st.top();
                st.pop();
                int temp1 = st.top();
                st.pop();
                if (tokens[i] == "+") {
                    st.push(temp1 + temp2);
                }
                else if (tokens[i] == "-") {
                    st.push(temp1 - temp2);
                }
                else if (tokens[i] == "*") {
                    st.push(temp1 * temp2);
                }
                else{
                    st.push(temp1 / temp2);
                }
            } else {
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        int ans = st.top();
        return ans;
    }
};