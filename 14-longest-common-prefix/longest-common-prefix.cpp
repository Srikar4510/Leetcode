class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";

        sort(strs.begin(),strs.end());
        string first = strs[0],last =strs[n-1];
        int i=0;

        while(i<first.size()&&first[i]==last[i]){
            i++;
        }

        return first.substr(0,i);
    }
};