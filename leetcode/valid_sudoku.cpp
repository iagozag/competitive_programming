#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++){
        map<char,int> mp_line;
        map<char,int> mp_column;
        for(int j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                if(mp_line.count(board[i][j])) return false;
                mp_line[board[i][j]]++;
            }
            if(board[j][i] != '.'){
                if(mp_column.count(board[j][i])) return false;
                mp_column[board[j][i]]++;
            }
        }
    }

    int beg1 = 0, beg2 = 0, lim1 = 3, lim2 = 3;
    for(int i = 0; i < 9; i++){
        map<char,int> mp_square;

        if(beg1 == 9){
            beg1 = 0; lim1 = 3;
            beg2 += 3; lim2 += 3;
        }

        for(int j = beg1; j < lim1; j++){
            for(int k = beg2; k < lim2; k++){
                if(board[j][k] == '.') continue;
                if(mp_square.count(board[j][k])) return false;
                mp_square[board[j][k]]++;
            }
        }
            
        beg1 += 3; lim1 += 3;
    }

    return true;
}

int main(){ _
    vector<vector<char>> sudoku = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};

    bool ans = isValidSudoku(sudoku);
    cout << ans << endl;

    exit(0);
}
