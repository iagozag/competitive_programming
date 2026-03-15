#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	int sum = 0; vector<int> v;
	for(int i = 0; i < n; i++){
		int x; cin >> x; sum += x;
		v.emplace_back(x);
	}

	sort(v.begin(), v.end());

	int prev = 0, ans = LINF;
	for(int i = 0; i < n; i++){
		int suf = sum-prev-v[i];
		ans = min(ans, i*v[i]-prev + suf-(n-i-1)*v[i]);
		prev += v[i];
	}

	cout << ans << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


