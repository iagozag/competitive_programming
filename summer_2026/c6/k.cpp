#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

vector<int> fib(MAX), dp(MAX);

void solve(){
	int n; cin >> n;
	cout << dp[n] << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;

	fib[1] = fib[2] = 1, fib[3] = 0; dp[1] = dp[2] = 0, dp[3] = 2;
	for(int i = 4; i < MAX; i++){
		fib[i] = (fib[i-1]+fib[i-2])%2;
		dp[i] = dp[i-1] + (fib[i-1]^fib[i]);
	}

	while(ttt--) solve();

	exit(0);
}


