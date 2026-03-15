#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	string s; cin >> s; int n = s.size();
	int ans = LINF; vector<int> pref(n);
	for(int i = 0; i < n; i++){
		if(i) pref[i] = pref[i-1];
		pref[i] += (s[i] == 'B' ? 1 : -1);
	}

	if(*min_element(pref.begin(), pref.end()) >= 0){ cout << 0 << endl; return; }

	int mi = LINF;
	for(int i = n-1; i >= 0; i--){
		if(pref[i] < 0 and mi-pref[i] >= 0) ans = i+1;

		mi = min(mi, pref[i]);
	}

	cout << ans << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


