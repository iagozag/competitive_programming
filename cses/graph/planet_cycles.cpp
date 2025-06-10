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
	int n; cin >> n;
	vector<int> child(n);
	for(auto& x: child) cin >> x, --x;

	vector<int> ans(n, -1); vector<int> vis(n);
	auto dfs = [&](auto&& self, int v) -> int{
		int c = ans[child[v]]; vis[v] = 1;
		return ans[v] = 1+(c == -1 ? self(self, child[v]) : c);
		
	};

	for(int i = 0; i < n; i++) if(ans[i] == -1) dfs(dfs, i);

	for(int i = 0; i < n; i++) cout << ans[i] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
