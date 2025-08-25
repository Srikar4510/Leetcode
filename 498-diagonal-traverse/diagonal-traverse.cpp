class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();        // number of rows
        int n = mat[0].size();     // number of columns
        
        vector<int> result;        // final answer array
        result.reserve(m * n);     // reserve space (optimization)

        // there are (m + n - 1) diagonals in total
        for (int k = 0; k < m + n - 1; k++) {
            vector<int> diag;      // temporary storage for this diagonal

            // ---- Find the head (starting cell) ----
            int r, c;
            if (k < n) {
                r = 0;         // top row
                c = k;
            } else {
                r = k - (n - 1);  // row shifts down
                c = n - 1;        // last column
            }

            // ---- Walk along the diagonal ----
            while (r < m && c >= 0) {
                diag.push_back(mat[r][c]);
                r++;
                c--;
            }

            // ---- Zig-zag adjustment ----
            if (k % 2 == 0) {
                reverse(diag.begin(), diag.end());
            }

            // ---- Add to result ----
            result.insert(result.end(), diag.begin(), diag.end());
        }

        return result;
    }
};
