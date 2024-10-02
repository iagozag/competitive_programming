#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

ll ans = 0;
vector<string> tab;

vector<vector<int>> d1, d2;

void place(int i, int col, int diag1, int diag2){
    if(i == 8){ ans++; return; }

    for(int j = 0; j < 8; j++){
        if(tab[i][j] == '.' and !(col&(1<<j)) and !(diag1&(1<<d1[i][j])) and !(diag2&(1<<d2[i][j]))) 
            place(i+1, col|(1<<j), diag1|(1<<d1[i][j]), diag2|(1<<d2[i][j]));
    }
}

void solve(){
    for(int i = 0; i < 8; i++){
        string s; cin >> s; tab.emplace_back(s);
    }

    int n = 8;
    d1 = d2 = vector<vector<int>>(n, vector<int>(n));
    for(int i = 0; i < n; i++) d1[0][i] = i, d2[0][i] = n-i-1;
    for(int i = 1; i < n; i++) for(int j = 0; j < n; j++) d1[i][j] = d1[i-1][j]+1, d2[i][j] = d2[i-1][j]+1;

    place(0, 0, 0, 0);
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
