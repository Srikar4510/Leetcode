class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> res;
        res.reserve(m*n);  

        for(int k=0;k<m+n-1;k++){
            vector<int> diag;

            int r,c;
            if(k<n){
               r = 0;
               c = k;    
            }else{
                r = k-(n-1);
                c = n-1;
            }  

            while(r<m && c>=0){
                diag.push_back(mat[r][c]);
                r++;
                c--;
            }  

            if(k%2==0){
                reverse(diag.begin(),diag.end());
            }  

            res.insert(res.end(),diag.begin(),diag.end());
        }
        return res;
    }
};