class Solution {
public:
//we transpose the matrix and then reverse each row
//(transposing means changing columns to rows and rows to columns)

/*
Before Transpose
1 2 3
4 5 6
7 8 9

After Transpose

1 4 7
2 5 8
3 6 9
*/
void rotate(vector<vector<int>>& matrix) {
     int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n; i++) {// Loop over rows
    for (int j = 0; j < i; j++) {// // Loop over columns (only lower triangle)
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
    }
};