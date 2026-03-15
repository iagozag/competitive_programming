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
	int k = 0;
	vector<tuple<int, int, int>> v(n); for(auto& [a, b, c]: v) cin >> a >> b, c = k++;
	sort(v.begin(), v.end());

	k = 1;
	int m; cin >> m;
	vector<tuple<int, int, int>> w(m); for(auto& [a, b, c]: w) cin >> a >> b, c = k++;
	sort(w.begin(), w.end());

	int j = m-1; vector<int> ans(n); set<pair<int, int>> st;
	for(int i = n-1; i >= 0; i--){
		auto [a, b, c] = v[i];
		while(j >= 0){
			auto [a1, b1, c1] = w[j];
			if(a1 < a) break;
			st.insert(make_pair(b1, c1)), j--;
		}

		auto it = st.lower_bound(make_pair(b, -1));
		if(it == st.end()){ cout << -1 << endl; return; }

		ans[c] = it->second;
		st.erase(it);
	}

	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
