#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	string s; cin >> s; int n = s.size();
	int ans = 0;
	for(int i = n-1, p = 1, j = 0; i >= 0; i--, p = p*10%MOD){
		ans += ((((i*(i+1)/2)%MOD*p%MOD) + j)%MOD)*(s[i]-'0')%MOD, ans %= MOD;
		j = (j+((n-i)*p%MOD))%MOD;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
