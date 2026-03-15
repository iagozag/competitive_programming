#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

struct Seg {
	vector<int> seg;
	int n;

	void build() {
		for (int i = n - 1; i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);
	}

	void build(int _n, int* v){
		n = _n; seg = vector<int>(2*n);
		for(int i = 0; i < n; i++) seg[n+i] = v[i];
		build();
	}

	int query(int a, int b) {
		int ret = -LINF;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret = max(ret, seg[a]);
			if (b % 2 == 0) ret = max(ret, seg[b]);
		}
		return ret;
	}

	void update(int p, int x) {
		seg[p += n] = x;
		while (p /= 2) seg[p] = max(seg[2*p], seg[2*p+1]);
	}
};

void solve(){
	int n, k, x; cin >> n >> k >> x;
	vector<int> v(n+1); for(int i = 1; i <= n; i++) cin >> v[i];

	int arr[n+1]; for(int i = 0; i <= n; i++) arr[i] = -LINF;
	arr[0] = 0;
	Seg seg; seg.build(n+1, arr); arr[0] = -LINF;
	for(int j = 1; j <= x; j++){
		Seg cur; cur.build(n+1, arr);
		for(int i = 1; i <= n; i++){
			int a = max(0ll, i-k), b = i-1;
			int ma = v[i]+seg.query(a, b);

			cur.update(i, ma);

			// for(int l = 1; l <= k; l++) if(i-l >= 0) dp[i][j] = max(dp[i][j], dp[i-l][j-1]+v[i]);
		}

		swap(seg, cur);
	}

	int ans = seg.query(n-k+1, n);
	// for(int i = n; i > n-k; i--) ans = max(ans, dp[i][x]);
	cout << (ans >= 0 ? ans : -1) << endl;
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}
