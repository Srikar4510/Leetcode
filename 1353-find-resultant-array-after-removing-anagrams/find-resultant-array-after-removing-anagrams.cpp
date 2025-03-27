class Solution {
public:
    bool isAnagram(string s1,string s2){
        if(s1==s2) return true;

        int s1FreqMap[26] ={0};
        int s2FreqMap[26]={0};

        for(char ch:s1){
            s1FreqMap[ch-'a']++;
        }

        for(char ch:s2){
            s2FreqMap[ch-'a']++;
        }

        for(int i=0;i<26;i++){
            if(s1FreqMap[i]!=s2FreqMap[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
           if(!isAnagram(words[i],words[i-1])){
            ans.push_back(words[i]);
           }
        }
        return ans;
    }
};