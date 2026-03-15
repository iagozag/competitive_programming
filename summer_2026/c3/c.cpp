#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int MAX = 2e5+10, LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
	int n, k; cin >> n >> k;
	vector<int> p(k); for(auto& x: p) cin >> x;
	int nim[n+1]; nim[0] = 0;

	
	for(int i = 1; i <= n; i++){
		vector<int> mex(102);
		for(auto pp: p) if(i-pp >= 0) mex[nim[i-pp]] = 1;

		int ans = 0;
		for(int j = 0; j <= 101; j++) if(mex[j] == 0){ ans = j; break; }
		nim[i] = ans;
	}

	for(int i = 1; i <= n; i++) cout << (nim[i] == 0 ? 'L' : 'W');
	cout << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;
	while(ttt--) solve();

	exit(0);
}

