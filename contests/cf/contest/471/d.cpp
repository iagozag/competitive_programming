#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> z_function(vector<int> v){
	int n = v.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i < r) z[i] = min(r-i, z[i-l]);
		while(i+z[i] < n and v[z[i]] == v[i+z[i]]) z[i]++;
		if(i+z[i] > r) l = i, r = i+z[i];
	}

	return z;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;
	vector<int> diff;
	for(int i = 1; i < m; i++) diff.emplace_back(b[i]-b[i-1]);
	diff.emplace_back(LINF);
	for(int i = 1; i < n; i++) diff.emplace_back(a[i]-a[i-1]);

	vector<int> z = z_function(diff);
	int ans = 0;
	for(int i = 0; i < (int)z.size(); i++) ans += (z[i] == m-1);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
