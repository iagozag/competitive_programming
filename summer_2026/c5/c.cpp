#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n; cin >> n;

	int nim[101][101]; for(int i = 0; i < 101; i++) for(int j = 0; j < 101; j++) nim[i][j] = -1;

	for(int i = 0; i < 101; i++) nim[0][i] = nim[i][0] = nim[i][i] = 305;

	for(int i = 0; i < 101; i++) for(int j = 0; j < 101; j++) if(nim[i][j] == -1){
		vector<int> mex(310);
		for(int k = 1; k <= max(i, j); k++){
			if(i-k >= 0) mex[nim[i-k][j]] = 1;
			if(j-k >= 0) mex[nim[i][j-k]] = 1;
			if(i-k >= 0 and j-k >= 0) mex[nim[i-k][j-k]] = 1;
		}

		for(int k = 0; k < 310; k++) if(!mex[k]){ nim[i][j] = k; break; }
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b; ans ^= nim[a][b];
	}

	cout << (ans ? 'Y' : 'N') << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


