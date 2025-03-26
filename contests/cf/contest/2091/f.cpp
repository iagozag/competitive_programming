#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x, bit[i] %= MOD;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i], ret %= MOD;
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return ((((pref(r)%MOD) - (pref(l - 1)%MOD))%MOD)+MOD)%MOD;
	}
};

void solve(){
	int n, m, d; cin >> n >> m >> d;
	vector<vector<int>> v(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < m; j++) v[i][j] = s[j] == 'X';
	}
	reverse(v.begin(), v.end());

	Bit b1(m), b2(m), b3(m);
	for(int i = 0; i < m; i++) if(v[0][i]) b1.update(i, 1);
	
	for(int j = 0; j < m; j++) if(v[0][j]){
		b2.update(j, b1.query(max(0LL, j-d), min(m-1, j+d))%MOD);
	}

	b1 = b2;

	for(int i = 1; i < n; i++){
		b2 = b3 = Bit(m);

		for(int j = 0; j < m; j++) if(v[i][j]){
			b2.update(j, b1.query(max(0LL, j-d+1), min(m-1, j+d-1))%MOD);
		}

		for(int j = 0; j < m; j++) if(v[i][j]){
			b3.update(j, b2.query(max(0LL, j-d), min(m-1, j+d))%MOD);
		}

		b1 = b3;
	}

	cout << b1.query(0, m-1)%MOD << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
