#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, MOD = 1e9+7;

int v[MAX], dp[MAX][21], qnt[MAX], cl, cr, cost;

void f(int k, int l, int r, int optl, int optr){
	if(l > r) return;

	int mid = l+(r-l)/2, opt = optl, lim = min(optr, mid-1);

	while(cr < mid-1) cr++, qnt[v[cr+1]]++, cost += qnt[v[cr+1]]-1;
	while(cr > mid-1) cost -= qnt[v[cr+1]]-1, qnt[v[cr+1]]--, cr--;

	while(cl > lim+1) cl--, qnt[v[cl+1]]++, cost += qnt[v[cl+1]]-1;
	while(cl < lim+1) cost -= qnt[v[cl+1]]-1, qnt[v[cl+1]]--, cl++;

	for(int i = lim; i >= optl; i--){
		qnt[v[i+1]]++, cost += qnt[v[i+1]]-1;
		cl = min(cl, i);

		if(dp[mid][k] >= dp[i][k-1]+cost)
			dp[mid][k] = dp[i][k-1]+cost, opt = i;
	}

	f(k, l, mid-1, optl, opt);
	f(k, mid+1, r, opt, optr);
}

void solve(){
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> v[i];
	
	for(int i = 0; i < MAX; i++) for(int j = 0; j <= 20; j++) dp[i][j] = LINF;
	dp[0][0] = 0;

	for(int i = 1; i <= k; i++){
		for(int j = 0; j < MAX; j++) qnt[j] = 0;

		cl = 0, cr = -1, cost = 0;
		f(i, 1, n, 0, n-1);
	}

	cout << dp[n][k] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
