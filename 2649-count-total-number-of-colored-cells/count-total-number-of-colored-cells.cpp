class Solution {
public:
//1,4,8,12,........
//1+(4×1)+(4×2)+...+(4×(n−1))
//1+4x((n-1)xn)/2 = 1+2x((n-1)xn)
    long long coloredCells(int n) {
        return 1+ (long long)n*(n-1)*2;
    }
};