class Solution {
public:
//O(N),O(1)
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int s1FreqMap[26]={0};
        int s2FreqMap[26]={0};
        int numdiff =0;
        for(int i=0;i<s1.size();i++){
           char s1char = s1[i];
           char s2char = s2[i];

           if(s1char != s2char){
            numdiff++;

           if(numdiff>2){
                return false;
            }
           }

           s1FreqMap[s1char -'a']++;
           s2FreqMap[s2char-'a']++;
        }  

        for(int i=0;i<26;i++){
            if(s1FreqMap[i]!=s2FreqMap[i]){
                return false;
            }
        }
    return true;
    }
};