#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int seg[4 * MAX] = {0LL};
int k = 0;

void update(int p, int x) {
	seg[p += k] += x;
	while (p /= 2) seg[p] = max(seg[2*p], seg[2*p+1]);
}

void solve(){
	int n; cin >> n;
	set<int> st; vector<tuple<int, int, int>> v(n);
	for(int i = 0; i < n; i++){
		int a, b, x; cin >> a >> b >> x; st.insert(a), st.insert(b);
		v.emplace_back(a, b, x);
	}

	map<int, int> mp;
	for(auto& x: st) mp[x] = k++;

	vector<int> lines(k), columns(k); vector<vector<pair<int, int>>> has(k);
	for(auto& [a, b, x]: v) a = mp[a], b = mp[b], lines[a] += x, update(b, x), has[a].emplace_back(b, x);

	int ans = 0;
	for(int i = 0; i < k; i++){
		for(auto [c, x]: has[i]) update(c, -x);
		ans = max(ans, lines[i]+seg[1]);
		for(auto [c, x]: has[i]) update(c, x);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

