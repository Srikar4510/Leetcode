class Solution {
public:
//O(n^2),O(n)
    string removeOccurrences(string s, string part) {
        while(s.find(part)!= string::npos){
            int partStartIndex = s.find(part);
            s = s.substr(0,partStartIndex) + s.substr(partStartIndex + part.size());
        }
        return s;
    }
};