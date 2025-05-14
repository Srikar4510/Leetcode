class Solution {
public:
    const int MOD = 1e9+7;
    using Matrix = vector<vector<long long>>;
    
    Matrix multiply(Matrix &A,Matrix &B){
        int n = A.size();
        Matrix res(n,vector<long long>(n,0));

        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                for(int j=0;j<n;j++){
                    res[i][j] = (res[i][j]+A[i][k]*B[k][j])%MOD;
                }
            }
        }
        return res;
    }
    Matrix expoMat(Matrix base,long long power){
        int n = base.size();
        Matrix res(n,vector<long long>(n,0));

        for(int i=0;i<n;i++){
                res[i][i] = 1;
        }
        while(power){
            if(power%2){
                res = multiply(res,base);
            }
            base = multiply(base,base);
            power /= 2;
        }
        return res;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int N = 26;

        Matrix T(N,vector<long long>(N,0));

        for(int c =0; c<N;c++){
            for(int i=1;i<=nums[c];i++){
                int to = (c+i)%26;
                T[to][c] += 1;
            }
        }

        Matrix T_t = expoMat(T,t);

        vector<long long> freq(N,0);
        for(char ch:s){
            freq[ch-'a']++;
        }

        vector<long long> res(N,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                res[i] = (res[i]+T_t[i][j]*freq[j])%MOD;
            }
        }

        long long ans = 0;
        for(int i=0;i<N;i++){
            ans = (ans + res[i])%MOD;
        }
     return ans;
    }
};