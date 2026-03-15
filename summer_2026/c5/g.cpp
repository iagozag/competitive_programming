#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;
	sort(v.begin(), v.end());

	int cur = 0;
	for(int i = 0; i < n; i++){
		if(v[i] > cur+1){ cout << cur+1 << endl; return; }
		cur += v[i];
	}

	cout << cur+1 << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


