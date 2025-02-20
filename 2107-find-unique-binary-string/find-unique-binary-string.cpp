class Solution {
public:
    // string generate(int n,string current,unordered_set<string> &st){
    //     if(current.size()==n){
    //         if(st.find(current)==st.end()){
    //             return current;
    //         }
    //         return "";
    //     }
    //     string addZero=generate(n,current+"0",st);
    //     if(addZero.size()>0){
    //         return addZero;
    //     }
    //     return generate(n,current+"1",st);
    // }
    // string findDifferentBinaryString(vector<string>& nums) {
    //     int n = nums.size();
    //     unordered_set<string> st;
    //     for(auto str:nums){
    //         st.insert(str);
    //     }
    //     return generate(n,"",st);
        
    // }
    //Cantor's Diagonal Argument to construct a unique binary string
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans;
         //we Construct the result by flipping the diagonal elements 
        //so that it differes from each of the element in nums at atleast one postion
        //if it is diff at atleast one position it is a seperate string apart from the ones present in nums
        for(int i=0;i<n;i++){
            char curr=nums[i][i];
            ans += curr=='0'?"1":"0";
        }
        return ans;
    }
};