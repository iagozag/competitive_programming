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
	int n, p; cin >> n >> p;
	vector<int> v(n); for(auto& x: v) cin >> x;

	auto dfs = [&](auto&& self, int i, int cur) -> bool {
		if(cur == 0) return true;
		if(i == n) return false;

		return (self(self, i+1, (cur+v[i])%1440) | self(self, i+1, (cur+2*v[i])%1440) | self(self, i+1, cur));
	};

	cout << (dfs(dfs, 0, p) ? "YES" : "NO") << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
