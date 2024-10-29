#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int matrix1[8][8];
	for(int i = 0; i < 8; i++){
		string s; cin >> s;
		for(int j = 0; j < 8; j++){
			if(s[j] == '#') matrix1[i][j] = 1;
			else matrix1[i][j] = 0;
		}
	}

	int ans = 0;
	for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++){
		bool can = 1;
		for(int l = 0; l < 8; l++) if(matrix1[l][j]) can = 0;
		for(int l = 0; l < 8; l++) if(matrix1[i][l]) can = 0;
		if(can) ans++;
	}
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
