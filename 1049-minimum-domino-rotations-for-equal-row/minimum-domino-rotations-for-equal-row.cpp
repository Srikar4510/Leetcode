class Solution {
public:
    int check(int x,vector<int>& tops, vector<int>& bottoms){
        int topRotations =0;
        int bottomRotations =0;

        int n = tops.size();

        for(int i=0;i<n;i++){
            if(tops[i] != x && bottoms[i] != x){
                return INT_MAX;
            }
            else if(tops[i]!=x){
                topRotations++;
            }
            else if(bottoms[i]!=x){
                bottomRotations++;
            }
        }

        return min(topRotations,bottomRotations);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations1 = check(tops[0],tops,bottoms);
        int rotations2 = check(bottoms[0],tops,bottoms);

        int ans = min(rotations1,rotations2);

        return ans == INT_MAX ? -1 : ans;
    }
};