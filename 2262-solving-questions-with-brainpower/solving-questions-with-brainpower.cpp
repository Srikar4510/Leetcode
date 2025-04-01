class Solution {
public:
    long long Rec(int i,vector<vector<int>>& questions,vector<long long>& dp,int n){
        if(i>=n) return 0;
        if(dp[i] != -1){
            return dp[i];
        }
        long long take = questions[i][0] + Rec(i+questions[i][1]+1,questions,dp,n);
        long long notTake = Rec(i+1,questions,dp,n);

        return dp[i]=max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return Rec(0,questions,dp,n);
    }
};