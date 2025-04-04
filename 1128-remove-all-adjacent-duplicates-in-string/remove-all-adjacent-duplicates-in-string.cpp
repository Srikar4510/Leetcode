class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto ch:s) {
            if(!st.empty() && st.top() == ch) {
                //pair up the becacuse its duplicate
                st.pop();
            }
            else{
                st.push(ch);
            }
        } 

        string ans="";
        while(!st.empty()) {
            char ch= st.top();
            ans = ch + ans;
            st.pop();
        }

        return ans;
    }
};