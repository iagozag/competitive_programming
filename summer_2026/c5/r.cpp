#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> odd, even;
	for(int i = 0; i < 2*n; i++){
		int x; cin >> x;
		if(i&1) odd.emplace_back(x);
		else even.emplace_back(x);
	}

	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());

	int ans = 0;
	for(int i = 0; i < n; i++) ans += abs(odd[i]-even[n-i-1]);

	cout << ans << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}
