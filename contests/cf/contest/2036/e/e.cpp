#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m, Q; cin >> m >> n >> Q;
	vector<vector<ll>> v(n, vector<ll>(m));
	for(int i = 0; i < m; i++) for(int j = 0; j < n; j++){
		ll a; cin >> a; v[j][i] = a;
	}
	for(int i = 0; i < n; i++) for(int j = 1; j < m; j++) v[i][j] = v[i][j-1]|v[i][j];

	for(int qq = 0; qq < Q; qq++){
		int q; cin >> q; map<int, pair<ll, ll>> mp;
		for(int i = 0; i < q; i++){
			int a; char c; ll b; cin >> a >> c >> b; --a;
			if(!mp.count(a)) mp[a] = {0LL, LINF};
			if(c == '<') mp[a].second = min(mp[a].second, b-1);
			else mp[a].first = max(mp[a].first, b+1);
		}

		int l = 0, r = m-1; int mi = INF;	
		for(auto [a, b]: mp){
			if(b.first > b.second) mi = -1;
			int lb = lower_bound(v[a].begin(), v[a].end(), b.first)-v[a].begin();
			int ub = upper_bound(v[a].begin(), v[a].end(), b.second)-v[a].begin();
			l = max(l, lb), r = min(r, ub-1);	
			if(l > r) mi = -1;
		}
		mi = min(mi, l);

		if(mi == -1) cout << mi << endl;
		else cout << mi+1 << endl;
	}
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
