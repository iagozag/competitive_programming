#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n, k; cin >> n >> k;
	vector<int> v(n); for(auto& x: v) cin >> x;
	sort(v.begin(), v.end());

	int sum = 0;
	for(int i = 0; i < n-k; i++) sum += v[i];
	cout << max(sum, v.back()) << endl;
}

int32_t main(){ _
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


