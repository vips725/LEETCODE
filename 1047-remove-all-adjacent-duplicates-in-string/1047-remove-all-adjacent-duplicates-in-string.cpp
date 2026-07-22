class Solution {
public:
    string removeDuplicates(string s) {
        int n= s.size();
        stack<char>st;
        string res;
        for(int i= 0 ;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(st.top()==s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};