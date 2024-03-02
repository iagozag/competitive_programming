#include <bits/stdc++.h>

using namespace std;

int main(){
    
    vector<vector<int>> sudoku(9);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char n; cin >> n;
            if(n == '#') sudoku[i].push_back(0);
            else sudoku[i].push_back(n - '0');
        }
    }
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(sudoku[i][j] == 0){
                vector<bool> aux1 (9, false);
                vector<bool> aux2 (9, false);
                for(int k = 0; k < 9; k++){
                    if(sudoku[i][k] == 0) continue;
                    else aux1[sudoku[i][k] - 1] = true;
                }
                
                for(int k = 0; k < 9; k++){
                    if(sudoku[k][j] == 0) continue;
                    else aux2[sudoku[k][j] - 1] = true;
                }
                
                for(int k = 0; k < 9; k++){
                    if(aux1[k] == aux2[k] && aux1[k] == false){
                        sudoku[i][j] = k+1;
                    }
                }
            }
        }
    }
    
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(j == 8) cout << sudoku[i][j];
            else cout << sudoku[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
