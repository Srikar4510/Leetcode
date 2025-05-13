class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> cnt(26);

        for(char ch : s){
            cnt[ch - 'a']++;
        }

        while(t--){
            vector<long long> nxt(26);

            nxt[0]=cnt[25];
            nxt[1]=(cnt[0]+cnt[25])%MOD;

            for(int i=2;i<=25;i++){
                nxt[i]=cnt[i-1];
            }

            cnt = nxt;
        }
        
        long long result=0;
        for(int i=0;i<=25;i++){
            result = (result + cnt[i]) %MOD;
        }

        return result;
    }
};