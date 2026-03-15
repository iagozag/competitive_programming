#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

template<class T = int> struct bit2d {
	vector<T> X;
	vector<vector<T>> Y, t;

	int ub(vector<T>& v, T x) {
		return upper_bound(v.begin(), v.end(), x) - v.begin();
	}
	bit2d(vector<pair<T, T>> v) {
		for(int i = 0; i < (int)v.size(); i++) X.push_back(v[i].first);
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());

		t.resize(X.size() + 1);
		Y.resize(t.size());
		sort(v.begin(), v.end(), [](pair<T, T> a, pair<T, T> b) {
			return a.second < b.second; });
		for (int j = 0; j < (int)v.size(); j++) for (int i = ub(X, v[j].first); i < t.size(); i += i&-i)
			if (!Y[i].size() or Y[i].back() != v[j].second) Y[i].push_back(v[j].second);

		for (int i = 0; i < t.size(); i++) t[i].resize(Y[i].size() + 1);
	}

	void update(T x, T y, T v) {
		for (int i = ub(X, x); i < t.size(); i += i&-i)
			for (int j = ub(Y[i], y); j < t[i].size(); j += j&-j) t[i][j] += v;
	}

	T query(T x, T y) {
		T ans = 0;
		for (int i = ub(X, x); i; i -= i&-i)
			for (int j = ub(Y[i], y); j; j -= j&-j) ans += t[i][j];
		return ans;
	}
	T query(T x1, T y1, T x2, T y2) {
		return query(x2, y2)-query(x2, y1-1)-query(x1-1, y2)+query(x1-1, y1-1);
	}
};

int n, m;

void solve(){
	vector<pair<int, int>> upd;
	vector<int> v(n), pos(n); for(int i = 0; i < n; i++) cin >> v[i], --v[i], pos[v[i]] = i, upd.emplace_back(i, v[i]);

	bit2d<int> bit(upd); int ans = 0;
	for(int i = 0; i < n; i++) bit.update(i, v[i], 1);
	for(int i = 0; i < n; i++) ans += (0 <= i-1 ? bit.query(0, v[i], i-1, n-1) : 0)+(i+1 <= n-1 ? bit.query(i+1, 0, n-1, v[i]) : 0);

	for(int i = 0; i < m; i++){
		cout << ans/2 << endl;

		int x; cin >> x; --x;
		bit.update(pos[x], x, -1);
		
		ans -= 2*((0 <= pos[x]-1 ? bit.query(0, x, pos[x]-1, n-1) : 0)+(pos[x]+1 <= n-1 ? bit.query(pos[x]+1, 0, n-1, x) : 0));
	}
}

int32_t main(){ _
    while(cin >> n >> m) solve();

    exit(0);
}
