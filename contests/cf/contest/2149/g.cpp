#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
	int n, q; cin >> n >> q;
	vector<int> v(n+1); set<int> st;
	for(int i = 1; i <= n; i++) cin >> v[i], st.insert(v[i]);

	map<int, int> mp, mp_r; int k = 0;
	for(auto x: st) mp[x] = k, mp_r[k++] = x;

	vector<vector<int>> pos(n);
	for(int i = 1; i <= n; i++) v[i] = mp[v[i]], pos[v[i]].emplace_back(i);

	for(int i = 0; i < q; i++){
		int l, r; cin >> l >> r;
		
		set<int> ans;
		for(int j = 0; j < 50; j++){
			int idx = uniform(l, r), x = v[idx];
			int ub = upper_bound(pos[x].begin(), pos[x].end(), r)-pos[x].begin();
			int lb = lower_bound(pos[x].begin(), pos[x].end(), l)-pos[x].begin();

			if(ub-lb > (r-l+1)/3) ans.insert(x);
		}

		for(auto x: ans) cout << mp_r[x] << ' ';
		if(ans.size() == 0) cout << -1;
		cout << endl;
	}
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
