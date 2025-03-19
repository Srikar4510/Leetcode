class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto x:s){

            if(x=='('||x=='{'||x=='['){
                st.push(x);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char ch = st.top();
                if((x==')' and ch== '(') || (x=='}' and ch=='{') || (x==']' and ch=='[') ) {
                    st.pop();
                }
                else{
                    return false; 
                }      
            }
        }
        return st.empty();
    }
};