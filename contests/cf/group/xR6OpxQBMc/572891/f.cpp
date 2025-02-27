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
	int n, m; cin >> n >> m;
	int x, y; cin >> x >> y;

	int ans = 0;
	auto dfs = [&](auto&& self, int a, int b) -> void{
		if(a == x and b == y) return;
		if(a == n and b == m) ans++;

		if(a+1 <= n) self(self, a+1, b);
		if(b+1 <= m) self(self, a, b+1);
	};

	dfs(dfs, 1, 1);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
