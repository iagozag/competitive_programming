#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void yes(int ans){
	cout << ans << endl;
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<int> row(n), col(m);

	set<pair<int, int>> v;
	for(int i = 0; i < k; i++){
		int a, b; cin >> a >> b; --a, --b;
		v.insert({a, b}); row[a]++, col[b]++;
	}

	int ma = 0;
	for(int i = 0; i < m; i++) ma = max(ma, col[i]);

	vector<int> cols;
	for(int i = 0; i < m; i++){
		if(ma == col[i]) cols.emplace_back(i);
	}

	int ma2 = 0;
	for(int i = 0; i < n; i++) ma2 = max(ma2, row[i]);

	vector<int> rows;
	for(int i = 0; i < n; i++) if(row[i] == ma2) rows.emplace_back(i);

	int ans = ma+ma2-1;
	for(auto i: rows){
		for(auto j: cols){
			if(!v.count({i, j})) return yes(ans+1);
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
