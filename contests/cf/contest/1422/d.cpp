#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

namespace seg{
	int seg[2 * MAX];
	int n;

	void build() {
		for (int i = n - 1; i; i--) seg[i] = __lcm(seg[2*i], seg[2*i+1]);
	}

	int query(int a, int b) {
		int ret = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret += seg[a];
			if (b % 2 == 0) ret += seg[b];
		}
		return ret;
	}
};

void solve(){
	int n, q; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;
	
	cin >> q; int last = 0;
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		int l = (last+x)%n, r = (last+y)%n;

		last = seg::query(l, r);
		cout << last << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
