#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

struct Seg{
	int seg[2 * MAX];
	int n;

	void build() {
		for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
	}

	int query(int a, int b) {
		int ret = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret += seg[a];
			if (b % 2 == 0) ret += seg[b];
		}
		return ret;
	}

	void update(int p, int x) {
		seg[p += n] = x;
		while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
	}
};

void solve(){
	int n, q; cin >> n >> q;
	int v[n];
	for(int i = 0; i < n; i++){ cin >> v[i]; }

	Seg s1;
	for(int i = 0; i < n; i++) s1.seg[n+i] = v[i];

	s1.n = n;
	s1.build();

	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b; --a, --b;
		cout << s1.query(a, b) << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
