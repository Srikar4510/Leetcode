class Solution {
public:
//O(N),O(N)
    // string clearDigits(string s) {
    //  string ans;
    //     for(int i=0;i<s.size();i++){
    //         if(isdigit(s[i])&& !ans.empty()){
    //             ans.pop_back();
    //         } else{
    //             ans+=s[i];
    //         }
    //     }
    //     return ans;
    // }

//O(N),O(1)
 string clearDigits(string s) {
     int ansLength=0; 
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                ansLength=max(0,ansLength-1);
            } else{
                s[ansLength]=s[i];
                ansLength++;
            }
        }
        s.resize(ansLength);
        return s;
    }
};