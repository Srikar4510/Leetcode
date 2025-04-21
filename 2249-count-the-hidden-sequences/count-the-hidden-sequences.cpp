class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long maxValue =0,minValue =0,currentSum = 0;

        for(int num:differences){
            currentSum += num;
            minValue = min(minValue,currentSum);
            maxValue = max(maxValue,currentSum);
        }

        long long low = lower-minValue;
        long long high =upper- maxValue;
        
        return max(0LL,high-low+1);
    }
};