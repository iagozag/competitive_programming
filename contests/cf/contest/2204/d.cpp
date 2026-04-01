#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m, sz0, sz1;
vector<vector<int>> g;
vector<int> vis;

bool f(int st){
	bool bip = true;
	queue<int> q; q.push(st);
	vis[st] = 0, sz0++;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for(auto ve: g[v]) {
			if (vis[ve] == -1) {
				vis[ve] = vis[v]^1;
				if(vis[ve]) sz1++;
				else sz0++;
				q.push(ve);
			} else {
				bip &= vis[ve] != vis[v];
			}
		}
	}

	return bip;
}

void solve(){
	cin >> n >> m;
	g = vector<vector<int>>(n); vis = vector<int>(n, -1);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a);
	}

	int ans = 0;
	for(int i = 0; i < n; i++) if(vis[i] == -1){
		sz0 = 0, sz1 = 0;
		if(f(i)) ans += max(sz0, sz1);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
