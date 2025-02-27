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
	int n, m, k; cin >> n >> m >> k;
	vector<int> v(n); for(auto& x: v) cin >> x;

	vector<tuple<int, int, int>> ops(m);
	for(auto& [a, b, c]: ops) cin >> a >> b >> c, --a, --b;

	vector<int> diffop(m);
	for(int i = 0; i < k; i++){
		int l, r; cin >> l >> r; --l, --r;
		diffop[l]++;
		if(r < m-1) diffop[r+1]--;
	}
	for(int i = 1; i < m; i++) diffop[i] += diffop[i-1];

	vector<int> diffv(n);
	for(int i = 0; i < m; i++){
		auto [l, r, d] = ops[i];
		diffv[l] += d*diffop[i];
		if(r < n-1) diffv[r+1] -= d*diffop[i];
	}

	for(int i = 1; i < n; i++) diffv[i] += diffv[i-1];

	for(int i = 0; i < n; i++) cout << v[i]+diffv[i] << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
