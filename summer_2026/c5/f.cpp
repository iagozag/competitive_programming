#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n, d, k; cin >> n >> d >> k;
	vector<pair<int, int>> v(k), vr; for(auto& [a, b]: v) cin >> a >> b, vr.emplace_back(b, a);

	sort(v.begin(), v.end());
	sort(vr.begin(), vr.end());

	int idxmi = -1, mi = LINF, idxma = -1, ma = -LINF;
	for(int i = 1; i <= n-d+1; i++){
		int a = upper_bound(v.begin(), v.end(), make_pair(i+d-1, n+1))-v.begin();
		int b = upper_bound(vr.begin(), vr.end(), make_pair(i-1, n+1))-vr.begin();
		
		int ans = a-b;

		if(mi > ans) idxmi = i, mi = ans;
		if(ma < ans) idxma = i, ma = ans;
	}

	cout << idxma << ' ' << idxmi << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


