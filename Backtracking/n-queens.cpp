#include <vector>
#include <string>
using namespace std;
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
bool isValidState(int col, int n)
{
    return (col == n);
}
bool isCandidate(vector<string> state, int n, int row, int col)
{
    // check if other queens can attack here
    bool willAttack;

    willAttack = false;
    int dup_row = row, dup_col = col;

    // check horizontal line
    while (dup_col > 0)
    {
        dup_col--;
        if (state[dup_row][dup_col] == 'Q')
        {
            willAttack = true;
            break;
        }
    }

    // check upper diagonal
    dup_col = col;
    while (!willAttack && dup_row > 0 && dup_col > 0)
    {
        dup_row--;
        dup_col--;
        if (state[dup_row][dup_col] == 'Q')
        {
            willAttack = true;
            break;
        }
    }

    // check lower diagonal
    dup_row = row;
    dup_col = col;
    while (!willAttack && dup_row < n - 1 && dup_col > 0)
    {
        dup_row++;
        dup_col--;
        if (state[dup_row][dup_col] == 'Q')
        {
            willAttack = true;
            break;
        }
    }
    return !willAttack;
}
void search(int col, vector<string> &state, vector<vector<string>> &solutions, int n)
{
    if (isValidState(col, n))
    {
        // add to solutions
        solutions.push_back(state);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        // the recursion takes place here
        if (isCandidate(state, n, row, col))
        {
            state[row][col] = 'Q';
            search(col + 1, state, solutions, n);
            state[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    // initiate solution list, state which is a set
    vector<vector<string>> solutions;
    string s(n, '.');
    vector<string> state(n, s);
    search(0, state, solutions, n);
    return solutions;
}
