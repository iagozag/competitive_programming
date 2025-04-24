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
	vector<pair<int, int>> sorted;
	vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i], sorted.emplace_back(v[i], i);

	sort(sorted.begin(), sorted.end());

	if(m < sorted[0].first){ cout << n+1 << endl; return; }

	vector<int> vis(n);

	int j = 0;
	while(j < n and m >= sorted[j].first) m -= sorted[j].first, vis[sorted[j].second] = 1, j++;
	
	int ans = n-j+1;
	if(j < n and (vis[j] or m+sorted[j-1].first-v[j] >= 0)) ans--;

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
