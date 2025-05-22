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
	int n, q; cin >> n >> q;
	vector<int> v; vector<int> queries(q);
	for(int i = 0; i < q; i++){
		int x; cin >> x; v.emplace_back(x);
		queries[i] = x;
	}
	v.emplace_back(0), v.emplace_back(n);
	sort(v.begin(), v.end());

	map<int, pair<int, int>> mp;
	for(int i = 1; i < (int)v.size(); i++) mp[v[i-1]].second = v[i], mp[v[i]].first = v[i-1];
	mp[0].first = mp[n].second = -1;

	int ma = 0;
	for(auto [a, b]: mp){
		if(b.first != -1) ma = max(ma, a-b.first);
		if(b.second != -1) ma = max(ma, b.second-a);
	}

	vector<int> ans(q);
	for(int i = q-1; i >= 0; i--){
		ans[i] = ma;
		int x = queries[i];
		int l = mp[x].first, r = mp[x].second;
		mp[l].second = r, mp[r].first = l, ma = max(ma, r-l);
		mp.erase(x);
	}
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
