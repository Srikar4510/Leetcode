class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> delta(n+1,0);
        for(auto& q:queries){
            int l = q[0],r = q[1];
            delta[l] += 1;
            if(r+1<n){
                delta[r+1] -= 1;
            }
        }

        vector<int> coverCount(n,0);
        int running=0;
        for(int i=0;i<n;i++){
            running += delta[i];
            coverCount[i]=running;
        }

        for(int i=0;i<n;i++){
            if(coverCount[i]<nums[i]){
                return false;
            }
        }
        return true;
    }
};