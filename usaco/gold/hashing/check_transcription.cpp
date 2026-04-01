#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+9;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	vector<ll> h, p;
	str_hash(string s) : h(s.size()), p(s.size()) {
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
	string s, t; cin >> s >> t; int n = s.size(), m = t.size();
	if(n > m){ cout << 0 << endl; return; }

	vector<int> v; int swap = s[0] == '1';
	for(int i = 0; i < n; i++) v.emplace_back((s[i] == '1')^swap);
	int qnt0 = 0, qnt1 = 0;
	for(int i = 0; i < n; i++){
		if(v[i]) qnt1++;
		else qnt0++;
	}

	int ans = 0;
	str_hash<MOD> hash(t);
	for(int i = 1; i < m; i++){
		if((m-qnt0*i)%qnt1) continue;
		int sz1 = (m-qnt0*i)/qnt1;
		if(sz1 <= 0) break;

		int j = 0, k = 0, h0 = -1, h1 = -1;
		while(j < n and k < m){
			if(v[j] == 0){
				if(k+i-1 >= m) break;

				if(h0 == -1) h0 = hash(k, k+i-1);
				else if(h0 != hash(k, k+i-1)) break;
				k += i;
			}
			else{
				if(k+sz1-1 >= m) break;

				if(h1 == -1) h1 = hash(k, k+sz1-1);
				else if(h1 != hash(k, k+sz1-1)) break;
				k += sz1;
			}
			j++;
		}

		if(j == n and k == m and h0 != -1 and h1 != -1 and h0 != h1) ans++;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
