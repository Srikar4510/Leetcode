class Solution {
public:
//using map
    // bool divideArray(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     for(int num:nums){
    //         mp[num]++;
    //     }
    //     for(auto x: mp){
    //         if(x.second % 2 != 0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
//using set
     bool divideArray(vector<int>& nums) {
        unordered_set<int> st;
        for(int num:nums){
            if(st.count(num)){
                st.erase(num);
            }
            else{
                st.insert(num);
            }
        }
        return st.empty();
    }
};