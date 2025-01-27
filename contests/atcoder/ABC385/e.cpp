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
	vector<vector<int>> g(n);
	for(int i = 0; i < n-1; i++){ int a, b; cin >> a >> b; --a, b--; g[a].emplace_back(b), g[b].emplace_back(a); }

	int ans = INF;
	for(int v = 0; v < n; v++){
		priority_queue<int, vector<int>, greater<int>> pq;
		for(auto ve: g[v])
			pq.push(g[ve].size()-1);

		while(!pq.empty()){
			ans = min(ans, n-((int)pq.size()*pq.top()+(int)pq.size()+1));
			pq.pop();
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
