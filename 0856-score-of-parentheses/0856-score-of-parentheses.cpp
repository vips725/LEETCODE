class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(char c : s) {
            if(c == '(') {
                st.push(0); // marker
            } else {
                if(st.top() == 0) {
                    st.pop();
                    st.push(1); // "()"
                } else {
                    int sum = 0;
                    while(st.top() != 0) {
                        sum += st.top();
                        st.pop();
                    }
                    st.pop(); // remove marker
                    st.push(2 * sum);
                }
            }
        }
        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
