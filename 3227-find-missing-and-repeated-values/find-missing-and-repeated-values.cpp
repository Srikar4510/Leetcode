class Solution {
public:
//O(N^2),O(1)
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum=0,sqrSum=0;
        long long n = grid.size();
        long long N =  n*n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += grid[i][j];
                sqrSum += static_cast<long long>(grid[i][j])*grid[i][j];
            }
        }
        long long sumDiff = sum - N*(N+1)/2;
        long long sqrDiff = sqrSum - N*(N+1)*(2*N+1)/6;

        //x->repeated,y->missing
        int repeated = (sqrDiff/sumDiff + sumDiff)/2;
        int missing = (sqrDiff/sumDiff - sumDiff)/2;

        return {repeated,missing};

    }
};