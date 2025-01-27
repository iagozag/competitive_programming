#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+10, MOD = 1e9+7;

int s[MAX], ans[MAX]; 
pair<int, int> v[MAX], qu[MAX];

namespace bit {
	int bit[2][MAX+2];
	int n;

	void build(int n2, int* v) {
		n = n2;
		for (int i = 1; i <= n; i++)
			bit[1][min(n+1, i+(i&-i))] += bit[1][i] += v[i-1];
	}
	ll get(int x, int i) {
		ll ret = 0;
		for (; i; i -= i&-i) ret += bit[x][i];
		return ret;
	}
	void add(int x, int i, ll val) {
		for (; i <= n; i += i&-i) bit[x][i] += val;
	}
	ll get2(int p) {
		return get(0, p) * p + get(1, p);
	}
	ll query(int l, int r) {
		return get2(r+1) - get2(l);
	}
	void update(int l, int r, ll x) {
		add(0, l+1, x), add(0, r+2, -x);
		add(1, l+1, -x*l), add(1, r+2, x*(r+1));
	}
};

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

	int Q; cin >> Q;
	for(int i = 0; i < Q; i++) cin >> qu[i].first, qu[i].second = i;
	sort(qu, qu+Q);
	
	for(int i = 0; i < Q; i++) s[i] = qu[i].first;
	bit::build(Q, s);

	for(int i = 0; i < n; i++){
		int l = 0, r = Q-1, idxl = Q;
		while(l <= r){
			int m = l+(r-l)/2;
			if(bit::query(m, m) >= v[i].first) idxl = m, r = m-1;
			else l = m+1;
		}
		l = idxl, r = Q-1; int idxr = -1;
		while(l <= r){
			int m = l+(r-l)/2;
			if(bit::query(m, m) <= v[i].second) idxr = m, l = m+1;
			else r = m-1;
		}

		if(idxl <= idxr) bit::update(idxl, idxr, 1);
	}

	for(int i = 0; i < Q; i++) ans[qu[i].second] = bit::query(i, i);
	for(int i = 0; i < Q; i++) cout << ans[i] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
