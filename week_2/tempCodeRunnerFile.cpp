//  Write a program to compute the number of sudoku solutions 
// (fill the zero elements of a given partial sudoku table)

#include <bits/stdc++.h>
using namespace std;

int board[9][9];
int res = 0;

// check if the element of row r, col c can get value v
bool valid(int r, int c, int v) {
    // starting index of the square that the point belongs to
    int r_square = r - r % 3;
    int c_square = c - c % 3;

    // check row and col
    for(int k = 0; k < 9; ++k) {
        if(board[r][k] == v || board[k][c] == v) {
            return false;
        }
    }

    // check subsquare
    for(int i = r_square; i < r_square + 3; ++i) {
        for(int j = c_square; j < c_square + 3; ++j) {
            if(board[i][j] == v) return false;
        }
    }

    return true;
}

// flatten the board matrix into 1D index: index
void sudoku(int index) {
    // index starts from 0 to 80
    if(index == 81) {
        res++;
        return;
    }

    int r = index / 9;
    int c = index % 9;

    if(board[r][c] == 0) {
        for(int v = 1; v <= 9; ++v) {
            if(valid(r, c, v)) {
                board[r][c] = v;
                if(index == 80) res++;
                else {
                    sudoku(index + 1);
                }
            }
            // backtrack
            board[r][c] = 0;
        }
    } 
}

int main() {
    string s;

    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }

    sudoku(0);
    cout << res << endl;
}