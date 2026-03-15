#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	string s; cin >> s; int n = s.size();
	for(int i = 0; i <= n; i++){
		string ans = s; ans += string(i, ' '); int m = n+i;
		bool can = 1;
		for(int j = m-1; j >= m/2; j--){
			if(ans[j] == ' ') ans[j] = ans[m-j-1];
			else if(ans[j] != ans[m-j-1]){ can = 0; break; }
		}
		if(can){ cout << ans << endl; return; }
	}
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


