class Solution {
public:
    string simplifyPath(string path) {
        if (path.size() == 0) {
            return path;
        }
        path+="/";
        stack<string> st;
        int i = 1;
        string str = "";
        while (i < path.size()) {
            if (path[i] == '/') {
                if (str == ".") {
                    str = "";
                } else if (str == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                    str = "";
                } else {
                    if (str.length() != 0) {
                        st.push(str);
                    }

                    str = "";
                }
                i++;
                while (i < path.size() && path[i] == '/') {
                    i++;
                }
            } // "/" occur
            else {
                str += path[i];
                i++;
            } // "any element occur"
        }
        string ans = "";
        if(st.empty()){return "/";}
        while (!st.empty()) {
            ans = st.top() + ans;
            ans = "/" + ans;
            st.pop();
        }
        return ans;
    }
};