#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> seg;
int n;

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

void solve(){
	int N, a, b; cin >> N >> a >> b;
	vector<int> v(N); for(auto& x: v) cin >> x;
	n = N+1;
	seg = vector<int>(2*n);
	vector<int> pref(n);
	for(int i = 1; i < n; i++) pref[i] = pref[i-1]+v[i-1], update(i, pref[i]);

	int ans = -LINF;
	for(int i = a; i < n; i++) ans = max(ans, pref[i]-query(max(0LL, i-b), i-a));

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
