class Solution {
public:
//O(NLOGN),O(N)
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long>,greater<long>> pq(nums.begin(),nums.end());
        int ans=0;
        while(pq.top()<k){
            pq.pop();
            ans++;
        } 
        return ans;
    }
};