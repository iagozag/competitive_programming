#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

// Li-Chao Tree
//
// Adiciona retas (ax+b), e computa o minimo entre as retas
// em um dado 'x'
// Cuidado com overflow!
// Se tiver overflow, tenta comprimir o 'x' ou usar
// convex hull trick
//
// O(log(MA-MI)), O(n) de memoria

template<ll MI = ll(-1e9), ll MA = ll(1e9)> struct lichao {
	struct line {
		ll a, b;
		array<int, 2> ch;
		line(ll a_ = 0, ll b_ = LINF) :
			a(a_), b(b_), ch({-1, -1}) {}
		ll operator ()(ll x) { return a*x + b; }
	};
	vector<line> ln;

	int ch(int p, int d) {
		if (ln[p].ch[d] == -1) {
			ln[p].ch[d] = ln.size();
			ln.emplace_back();
		}
		return ln[p].ch[d];
	}
	lichao() { ln.emplace_back(); }

	void add(line s, ll l=MI, ll r=MA, int p=0) {
		ll m = (l+r)/2;
		bool L = s(l) < ln[p](l);
		bool M = s(m) < ln[p](m);
		bool R = s(r) < ln[p](r);
		if (M) swap(ln[p], s), swap(ln[p].ch, s.ch);
		if (s.b == LINF) return;
		if (L != M) add(s, l, m-1, ch(p, 0));
		else if (R != M) add(s, m+1, r, ch(p, 1));
	}
	ll query(int x, ll l=MI, ll r=MA, int p=0) {
		ll m = (l+r)/2, ret = ln[p](x);
		if (ret == LINF) return ret;
		if (x < m) return min(ret, query(x, l, m-1, ch(p, 0)));
		return min(ret, query(x, m+1, r, ch(p, 1)));
	}
};

int n;
vector<pair<int, int>> v;

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		v.emplace_back(a, b);
	}

	sort(v.begin(), v.end());

	int ma = 0;
	for(int i = n-1; i >= 0; i--){
		if(v[i].second <= ma) v[i] = {-1, -1};
		ma = max(ma, v[i].second);
	}
	vector<pair<int, int>> v2; for(auto x: v) if(x.first != -1) v2.push_back(x);
	swap(v, v2); n = v.size();

	if(n == 1){ cout << v[0].first*v[0].second << endl; return; }

	vector<int> dp(n);
	lichao<> l; l.add({v[0].second, 0});
	for(int i = 0; i < n; i++){
		dp[i] = l.query(v[i].first);
		if(i+1 < n) l.add({v[i+1].second, dp[i]});
	}

	cout << dp[n-1] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
