#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	string s, rr; cin >> s >> rr; int n = s.size();
	int l = n, r = 0;
	for(int i = 0; i < n; i++) if(s[i] != rr[i]){
		l = min(l, i), r = max(r, i);
	}

	reverse(s.begin()+l, s.begin()+r+1);

	cout << (s == rr ? "YES" : "NO") << endl;
}

int32_t main(){
	int ttt = 1; //cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


