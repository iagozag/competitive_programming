#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 4e5+10, MOD = 1e9+7;

ll seg[2 * MAX];
int n;

void build() {
	for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
}

ll query(int a, int b) {
	ll ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret += seg[a];
		if (b % 2 == 0) ret += seg[b];
	}
	return ret;
}

void update(int p, ll x) {
	seg[p += n] = x;
	while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
}

void solve(){
	cin >> n; fill(seg, seg+2*MAX, 0);
	vector<ll> a(n), b(n); 
	for(int i = 0; i < n; i++) cin >> a[i], update(i, a[i]); 
	for(auto& x: b) cin >> x, --x;

	vector<int> vis(n); int i = 0; ll ans = 0;
	while(i >= 0){
		if(vis[i]) i--;
		else if(b[i] > i and query(i+1, b[i]) >= a[i]) vis[i] = 1, update(i, 0), i = b[i];
		else vis[i] = 1, ans += a[i], update(i, 0), i--;
	}

	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
