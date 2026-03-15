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
	vector<int> p(n); for(auto& x: p) cin >> x, --x;

	vector<int> g(n); for(int i = 0; i < n; i++) g[i] = p[i];
	vector<int> vis(n);

	int ans = 0;
	for(int i = 0; i < n; i++) if(!vis[i]){
		int cur = i; int sz = 0;
		while(!vis[cur]){
			vis[cur] = 1, sz++;
			cur = g[cur];
		}

		if(sz > 1) ans += sz*(sz-1)/2;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
