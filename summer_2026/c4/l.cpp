#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;
	sort(v.begin(), v.end());

	for(int i = 0; i < n-2; i++) for(int k = i+2; k < n; k++){
		int j = i+1;
		if(v[i]+v[j] > v[k] and v[i]+v[k] > v[j] and v[j]+v[k] > v[i]){ cout << "possible" << endl; return; }
	}

	cout << "impossible" << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;
	while(ttt--) solve();

	exit(0);
}

