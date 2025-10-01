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
		for (int i = n - 1; i; i--) seg[i] = min(seg[2*i], seg[2*i+1]);
	}

	int query(int a, int b) {
		int ret = LINF;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret = min(seg[a], ret);
			if (b % 2 == 0) ret = min(seg[b], ret);
		}
		return ret;
	}

	void update(int p, int x) {
		seg[p += n] = x;
		while (p /= 2) seg[p] = min(seg[2*p], seg[2*p+1]);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	int v1[n], v2[n];
	for(int i = 0; i < n; i++){ int x; cin >> x; v1[i] = x+i, v2[i] = x+n-i+1; }

	Seg s1, s2;
	for(int i = 0; i < n; i++) s1.seg[n+i] = v1[i], s2.seg[n+i] = v2[i];

	s1.n = n, s2.n = n;
	s1.build(), s2.build();

	for(int i = 0; i < q; i++){
		int op, a, b; cin >> op;
		if(op == 1){
			cin >> a >> b; --a;
			s1.update(a, a+b), s2.update(a, b+n-a+1);
		} else{
			cin >> a; --a;
			cout << min(s1.query(a, n-1)-a, s2.query(0, a)-(n-a+1)) << endl;
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
