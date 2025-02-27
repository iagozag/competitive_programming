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
	int n, a, b; cin >> n >> a >> b;

	vector<long double> dp(n+1), pref(n+1);
	if(a == 0){
		for(int i = 1; i <= n; i++){
			int l = max(i-b, 0LL), r = max(i-a-1, l);
			dp[i] = (1.0/(long double)(b-a))*((long double)(b-a+1) + (pref[r]-(l ? pref[l-1] : 0)));
			pref[i] = pref[i-1]+dp[i];
		}
	} else{
		for(int i = 1; i <= n; i++){
			int l = max(i-b, 0LL), r = max(i-a, l);
			dp[i] = 1.0 + (1.0/(long double)(b-a+1))*(pref[r]-(l ? pref[l-1] : 0));
			pref[i] = pref[i-1]+dp[i];
		}
	}

	cout << fixed << setprecision(12) << dp[n] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
