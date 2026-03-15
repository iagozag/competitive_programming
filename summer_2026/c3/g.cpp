#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int long long
#define endl '\n'

typedef long long ll;

const int MAX = 4e5+10, LINF = 0x3f3f3f3f3f3f3f3fll;

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

int n;

void solve(){
	vector<int> ans(n);
	vector<tuple<int, int, int>> v(n); set<int> st;
	for(int i = 0; i < n; i++){ int a, b; cin >> a >> b; v[i] = {a, b, i}, st.insert(a), st.insert(b); }

	map<int, int> mp; int k = 0;
	for(auto x: st) mp[x] = k++;
	for(auto& [a, b, i]: v) a = mp[a], b = mp[b];

	sort(v.begin(), v.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b){
		auto [a1, b1, c1] = a;
		auto [a2, b2, c2] = b;
		if(a1 != a2) return a1 <= a2;
		return b1 >= b2;
	});

	Bit bit(k); 

	map<pair<int, int>, int> rep;
	for(auto [a, b, c]: v){
		ans[c] += bit.query(b, k-1)-(rep.count({a, b}) ? rep[{a, b}] : 0);
		bit.update(b, 1);
		rep[{a, b}]++;
	}

	for(auto x: ans) cout << x << ' ';
	cout << endl;

	for(auto [a, b, c]: v){
		bit.update(b, -1);
	}
}

int32_t main(){ _
	while(cin >> n) solve();

	exit(0);
}
