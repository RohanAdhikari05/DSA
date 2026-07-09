class Solution {
public:
    string decodeString(string s) {

        stack<string> st;     
        stack<int> num;  

        string ans = "";
        string temp = "";
        int number = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                number = number * 10 + (ch - '0');
            }

            else if (ch == '[') {
                st.push(temp);
                num.push(number);
                number = 0;
                temp = "";
            }
            else if (ch == ']') {
                int n = num.top();
                num.pop();

                string temp1 = "";

                while (n--) {
                    temp1 += temp;
                }
                temp = st.top() + temp1;
                st.pop();
            }
            else {
                temp += ch;
            }
        }
        ans = temp;
        return ans;
    }
};