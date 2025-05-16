class Solution {
public:
    int HammingDistance(string& a,string& b){
        if(a.size()!=b.size()){
            return -1;
        }
        int dis =0;
        for(int i =0;i<a.size();i++){
            if(a[i]!=b[i]){
                dis++;
            }
        }
        return dis;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        int lastIndex =0;
        int maxlen = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[i]!=groups[j] && HammingDistance(words[i],words[j])==1){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }
            }
            if(dp[i]>maxlen){
                maxlen = dp[i];
                lastIndex = i;
            }
        }

        vector<string> res;
        int curr = lastIndex;

        while(curr != -1){
            res.push_back(words[curr]);
            curr = prev[curr];
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};