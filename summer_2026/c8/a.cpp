#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

vector<int> get_z(vector<int> s) {
	int n = s.size();
	vector<int> z(n, 0);

	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}

	return z;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	vector<int> diff, diff2;
	for(int i = 1; i < n; i++) diff.emplace_back(a[i]-a[i-1]);
	for(int i = 1; i < m; i++) diff2.emplace_back(b[i]-b[i-1]);

	vector<int> v;
	for(auto x: diff2) v.emplace_back(x);
	v.emplace_back(LINF);
	for(auto x: diff) v.emplace_back(x);

	vector<int> z = get_z(v);

	int ans = 0;
	for(int i = 0; i < (int)z.size(); i++) if(z[i] == m-1) ans++;
	cout << ans << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


