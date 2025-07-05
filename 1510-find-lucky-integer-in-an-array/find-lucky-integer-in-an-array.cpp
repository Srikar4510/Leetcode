class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int ans =-1;
        for(auto num:arr){
            mp[num]++;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]==mp[arr[i]]){
                ans = max(arr[i],ans);
            }
        }
        return ans;
    }
};