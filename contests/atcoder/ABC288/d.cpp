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
	int n, k; cin >> n >> k;
	vector<int> v(n), diff(n); for(auto& x: v) cin >> x;
	for(int i = 1; i < n; i++) diff[i] = v[i]-v[i-1];
	diff[0] = v[0];

	vector<vector<int>> pref(k, vector<int>(n));

	for(int i = 0; i < n; i++){
		pref[i%k][i/k] = (i/k ? pref[i%k][i/k-1] : 0)+diff[i];
	}
	
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b; --a, --b;
		bool can = 1; int idx = (b-k+1)%k;
		for(int j = 0; j < k; j++) if(j != idx and pref[j][b/k]-((a+k-1)/k ? pref[j][(a+k-1)/k-1] : 0)) can = 0;
		cout << (can ? "Yes" : "No") << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
