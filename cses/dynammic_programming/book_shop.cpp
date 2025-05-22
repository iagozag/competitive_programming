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
	int n, x; cin >> n >> x;
	vector<int> h(n), s(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 0; i < n; i++) cin >> s[i];

	vector<int> dp(x+1);
	for(int i = 0; i < n; i++) for(int j = x; j >= 0; j--){
		if(j) dp[j] = max(dp[j], dp[j-1]);
		if(j-h[i] >= 0) dp[j] = max(dp[j], dp[j-h[i]]+s[i]);
	}

	cout << dp[x] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
