class Solution {
// public:
// //O(n^2),O(n)
//     string removeOccurrences(string s, string part) {
//         while(s.find(part)!= string::npos){
//             int partStartIndex = s.find(part);
//             s = s.substr(0,partStartIndex) + s.substr(partStartIndex + part.size());
//         }
//         return s;
//     }
public:
//O(n.m),O(n+m)
    string removeOccurrences(string s, string part) {
        stack<char> stk;
        
        int strLength = s.size();
        int partLength = part.size();
        for(int i=0;i<strLength;i++){
            stk.push(s[i]);
            if(stk.size()>=partLength && checkPart(stk,part,partLength)){
                for(int j=0;j<partLength;j++){
                    stk.pop();
                }
            }
        }
      string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }

        return result;
    }
private:
  bool checkPart(stack<char> &stk,string &part,int partLength){
    stack<char> tmp =stk;
    for(int i=partLength-1;i>=0;i--){
        if(tmp.top()!=part[i]){
            return false;
        }
        tmp.pop();
    }
    return true;
  }
       
};