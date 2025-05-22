#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n;
	cin >> n;

	int mat[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			vector<int> vis(2*n);
			for(int k = 0; k < i; k++) if(mat[k][j] < 2*n) vis[mat[k][j]] = 1;
			for(int k = 0; k < j; k++) if(mat[i][k] < 2*n) vis[mat[i][k]] = 1;

			for(int k = 0; k < 2*n; k++) if(!vis[k]){ mat[i][j] = k; break; }
		}
	}

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cout << mat[i][j] << " \n"[j==n-1];
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
