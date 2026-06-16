/* Problem Statement :
You are given a chessboard of dimensions N × N. Your task is to place N queens on the chessboard such that no two queens attack each other. A queen can attack another piece if they are positioned in the same row, column, or diagonal. You need to find all distinct valid configurations of the chessboard.

Function Name : solveNQueens – This function finds all unique valid placements of N queens on an N × N chessboard.
Parameters : N (integer) – The size of the chessboard and the number of queens to place.
Return Value : A vector of vectors of strings, where each inner vector represents a valid configuration of the chessboard. Each string in the inner vector represents a row of the chessboard, with 'Q' indicating a queen and '.' indicating an empty space. */

/* Input Format : 
A single line containing an integer N, representing the size of the chessboard.
Output Format : 
The output consists of all distinct valid configurations of the chessboard, each represented as a vector of strings.
Constraints : 
1 ≤ N ≤ 9 */

/* Sample Input : 
4
Sample output :
. . Q .
Q . . .
. . . Q
. Q . .

. Q . .
. . . Q
Q . . .
. . Q . */


#pragma endregion
#include <iostream>
#include <vector>

using namespace std;

vector < vector < string >> solveNQueens(int N) {
    //write your code here
    vector < vector < string >> ans;
    vector < string > board(N, string(N, '.'));

    vector < int > column(N, 0);
    vector < int > diagram1(2 * N - 1, 0);
    vector < int > diagram2(2 * N - 1, 0);

    function < void(int) > dfs = [ & ](int row)
    {
        if (row == N)
        {
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < N; c++)
        {
            if (diagram1[row - c + N - 1] || diagram2[row + c])
            {
                continue;
            }

            board[row][c] = 'Q';
            column[c] = 1;
            diagram1[row - c + N - 1] = 1;
            diagram2[row + c] = 1;

            dfs(row + 1);

            board[row][c] = '.';
            column[c] = 0;
            diagram1[row - c + N - 1] = 0;
            diagram2[row + c] = 0;
        }
    };

    dfs(0);
    return ans;
}









