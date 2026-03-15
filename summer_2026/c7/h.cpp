#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	string s, t; cin >> s >> t;
	int n = s.size(); vector<int> p(n);
	for(int i = 0; i < n; i++) cin >> p[i], --p[i];

	int l = 0, r = n, ans = 0;
	while(l <= r){
		int m = l+(r-l)/2;

		vector<int> can(n, 1);
		for(int i = 0; i < m; i++) can[p[i]] = 0;

		int j = 0; 
		for(int i = 0; i < n; i++) if(can[i] and s[i] == t[j]) j++;

		if(j == (int)t.size()) l = m+1, ans = m;
		else r = m-1;
	}	

	cout << ans << endl;
}

int32_t main(){
	int ttt = 1; //cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


