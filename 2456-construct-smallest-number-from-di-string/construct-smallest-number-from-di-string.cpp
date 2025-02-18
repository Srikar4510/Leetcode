class Solution {
public:
//O(N),O(N)
    string smallestNumber(string pattern) {
        string ans;
        stack<int> stk;
        for(int index=0;index<=pattern.size();index++){
            stk.push(index+1);
            if(pattern[index]=='I'||index==pattern.size()){
                while(!stk.empty()){
                    ans+=to_string(stk.top());
                    stk.pop();
                }
            }
        }  
        return ans; 
    }
};