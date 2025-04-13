class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast exponentiation: computes (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // even indices: 0,2,4,...
        long long oddCount = n / 2;         // odd indices: 1,3,5,...

        long long evenWays = power(5, evenCount);  // 5 choices at even places
        long long oddWays = power(4, oddCount);    // 4 choices at odd places

        return (evenWays * oddWays) % MOD;
    }
};
