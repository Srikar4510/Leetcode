class Solution {
public:
    vector<int> pascal(int row){
        vector<int> ans;
        long long res =1;
        ans.push_back(res);
        for(int col=1;col<row;col++){
            res=res*(row-col);
            res=res/col;
            ans.push_back(res);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
        ans.push_back(pascal(i));
        }
        return ans;
    }
};