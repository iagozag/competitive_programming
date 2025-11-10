#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, MOD = 1e9+7;

int v[MAX], dp[MAX][21], qnt[MAX];

void f(int k, int l, int r, int optl, int optr){
	if(l > r) return;

	int mid = l+(r-l)/2, opt = optl, cost = 0;

	for(int i = mid-1; i > min(optr, mid-1); i--) 
		qnt[v[i+1]]++, cost += qnt[v[i+1]]-1;

	for(int i = min(optr, mid-1); i >= optl; i--){
		qnt[v[i+1]]++, cost += qnt[v[i+1]]-1;

		if(dp[mid][k] >= dp[i][k-1]+cost)
			dp[mid][k] = dp[i][k-1]+cost, opt = i;
	}

	for(int i = mid-1; i > min(optr, mid-1); i--) 
		cost -= qnt[v[i+1]]-1, qnt[v[i+1]]--;

	for(int i = min(optr, mid-1); i >= optl; i--)
		cost -= qnt[v[i+1]]-1, qnt[v[i+1]]--;

	f(k, l, mid-1, optl, opt);
	f(k, mid+1, r, opt, optr);
}

void solve(){
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> v[i];
	
	for(int i = 0; i < MAX; i++) for(int j = 0; j <= 20; j++) dp[i][j] = LINF;
	dp[0][0] = 0;

	for(int i = 1; i <= k; i++) f(i, 1, n, 0, n-1);

	cout << dp[n][k] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
