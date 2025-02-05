class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1==s2) return true;
        int s1FreqMap[26]={0};
        int s2FreqMap[26]={0};
         
         for(int i=0;i<s1.size();i++){
            s1FreqMap[s1[i]-'a']++;
         }
         for(int i=0;i<s2.size();i++){
            s2FreqMap[s2[i]-'a']++;
         }

         for(int i=0;i<26;i++){
            if(s1FreqMap[i]!=s2FreqMap[i]){
                return false;
            }
         }
         return true;
    }
};