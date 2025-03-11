class Solution {
private:
 bool hasAll(vector<int> &freq){
    return freq[0]>0 && freq[1]>0 && freq[2]>0;
 }
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left=0,right=0;
        int ans =0; 
        vector<int> freq(3,0);
        while(right<n){
            char curr = s[right];
            freq[curr-'a']++;
            while(hasAll(freq)){
                ans += n-right;
                freq[s[left]-'a']--;
                left++;
            } 
            right++;
        }
        return ans;
    }
};