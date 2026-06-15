// Given an m x n binary matrix mat, return the number of special positions in mat.
// A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).
// Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
// Output: 1
// Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.

#include <iostream>
#include <vector>   
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && row[i]==1 && col[j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,0,0},{0,0,1},{1,0,0}};
    int result = sol.numSpecial(mat);
    cout << "Number of special positions: " << result << endl;
    return 0;
}