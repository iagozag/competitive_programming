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
	int n, Q; cin >> n >> Q;
	int v[n][n];
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){ char a; cin >> a; v[i][j] = (a == '*'); }

	int pref[n+1][n+1]; memset(pref, 0, sizeof pref);
	for(int i = 1; i < n+1; i++) for(int j = 1; j < n+1; j++){
		pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+v[i-1][j-1];
	}

	for(int i = 0; i < Q; i++){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1] << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
