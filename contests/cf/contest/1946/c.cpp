#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, k;
vector<vector<int>> g;
vector<int> child;

int tot = 0;
int dfs(int v, int p, int x){
	for(auto ve: g[v]) if(ve != p){
		child[v] += dfs(ve, v, x);
	}

	if(child[v] >= x and v){
		tot++, child[p] -= child[v];
	}

	return child[v];
}

void solve(){
	cin >> n >> k;

	g = vector<vector<int>>(n), child = vector<int>(n);
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a);
	}

	int l = 2, r = n, ans = 1;
	while(l <= r){
		int mid = l+(r-l)/2;

		tot = 0; child = vector<int>(n, 1);
		dfs(0, -1, mid);

		if((tot == k and child[0] >= mid) or tot > k) ans = mid, l = mid+1;
		else r = mid-1;
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
