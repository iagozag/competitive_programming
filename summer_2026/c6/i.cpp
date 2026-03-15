#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	string s; cin >> s;
	string ans = "";
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] >= '0' and s[i] <= '9') ans += s[i];
		else break;
	}
	
	if(ans == "") cout << -1 << endl;
	else cout << ans << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


