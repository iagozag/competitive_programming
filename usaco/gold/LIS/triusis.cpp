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
	int n, m; cin >> n >> m; n++;
	vector<int> v(n);
	for(int i = 1; i < n; i++) cin >> v[i];

	for(int i = 1; i < n; i++) v[i] = m*i-v[i];

	vector<int> dp(n+1, LINF); dp[0] = 0;
	for(int i = 1; i < n; i++) if(v[i] >= 0){
		int ub = upper_bound(dp.begin(), dp.end(), v[i])-dp.begin();
		dp[ub] = v[i];
	}

	int ma = 0;
	for(int i = 0; i < n+1; i++) if(dp[i] != LINF) ma = i;

	cout << n-1-ma << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
