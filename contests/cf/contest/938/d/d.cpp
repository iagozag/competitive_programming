#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b; ll w; cin >> a >> b >> w; g[a].emplace_back(b, w), g[b].emplace_back(a, w);
	}
	vector<ll> dist(n); for(auto& x: dist) cin >> x;

	for(int i = 0; i < n; i++){
		
	}
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
