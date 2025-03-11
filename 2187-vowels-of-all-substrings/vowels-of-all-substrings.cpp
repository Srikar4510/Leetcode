class Solution {
private: 
    bool isVowel(char ch){
       return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
public:
    long long countVowels(string word) {
        int n = word.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(isVowel(word[i])){
                ans += (long)(n-i)* (long)(i+1);
            }
        }
        return ans;
    }
};