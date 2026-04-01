#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7, MOD2 = 1e9+9;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	vector<ll> h, p;
	str_hash() {}
	str_hash(vector<int>& s) : h(s.size()), p(s.size()) {
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = p[i - 1]*P%MOD, h[i] = (h[i - 1]*P + s[i])%MOD;
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
		ll hash = h[r] - (l ? h[l - 1]*p[r - l + 1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1); // l > |sigma|

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		char c; cin >> c;
		v[i][j] = (c == '*');
	}

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) v[i].emplace_back(v[i][j]);
	for(int i = 0; i < n; i++) v.push_back(v[i]);

	vector<str_hash<MOD>> hr(2*n), hc(m);
	vector<str_hash<MOD2>> hr2(2*n), hc2(m);
	for(int i = 0; i < 2*n; i++) hr[i] = str_hash<MOD>(v[i]), hr2[i] = str_hash<MOD2>(v[i]);
	for(int j = 0; j < m; j++){
		vector<int> col, col2;
		for(int i = 0; i < 2*n; i++) col.emplace_back(hr[i](j, j+m-1)), col2.emplace_back(hr2[i](j, j+m-1));
		hc[j] = str_hash<MOD>(col), hc2[j] = str_hash<MOD2>(col2);
	}

	// for(int i = 0; i < 2*n; i++) for(int j = 0; j < 2*m; j++) cout << v[i][j] << " \n"[j==2*m-1];

	int bi = 0, bj = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		// find first diff row
		int l = 0, r = n-1, row = r, col;
		while(l <= r){
			int mid = l+(r-l)/2;

			if(hc[j](i, i+mid) != hc[bj](bi, bi+mid) or hc2[j](i, i+mid) != hc2[bj](bi, bi+mid)) row = mid, r = mid-1;
			else l = mid+1;
		}

		// find first diff char in row
		l = 0, r = m-1, col = r;
		while(l <= r){
			int mid = l+(r-l)/2;

			if(hr[i+row](j, j+mid) != hr[bi+row](bj, bj+mid) or hr2[i+row](j, j+mid) != hr2[bi+row](bj, bj+mid)) col = mid, r = mid-1;
			else l = mid+1;
		}

		if(v[bi+row][bj+col] < v[i+row][j+col]) bi = i, bj = j;
	}


	for(int i = bi; i < bi+n; i++){
		for(int j = bj; j < bj+m; j++)
			cout << (v[i][j] ? '*' : '.');
		cout << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
