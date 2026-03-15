#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	map<int, int> mp; for(int i = 0; i < n; i++){ int x; cin >> x; mp[x]++; }
	int qnt = 0;
	for(auto& [a, b]: mp){
		if(b&1) b--;
		qnt += b;
	}

	cout << qnt/4 << endl;
}

int32_t main(){
	int ttt = 1; //cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


