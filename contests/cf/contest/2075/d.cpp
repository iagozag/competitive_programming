#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int dp[64][64];

void solve(){
	int x, y; cin >> x >> y;
	if(x < y) swap(x, y);

	if(x == y){ cout << 0 << endl; return; }

	int ans = LINF;

	int la = 0, lb = -1;
	for(int i = 0; i < 64; i++){
		if(x&(1LL<<i)) la = i;
		if(y&(1LL<<i)) lb = i;
	}

	int pa = la+1, pb = lb+1;

	while(lb >= 0 and ((x>>la)&1) == (((y>>lb))&1)) la--, lb--;
	la++, lb++;

	while(la < 64) ans = min(ans, dp[la][lb]), la++, lb++;
	for(int i = pa; i < 64; i++) for(int j = pb; j < 64; j++) ans = min(ans, dp[i][j]);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	for(int i = 0; i < 64; i++) for(int j = 0; j < 64; j++) dp[i][j] = LINF;
	dp[0][0] = 0;

	for(int i = 1; i < 63; i++){
		for(int j = 63; j >= 0; j--) for(int k = 63; k >= 0; k--){
			int l1 = min(j+i, 63LL), l2 = min(k+i, 63LL);
			dp[l1][k] = min(dp[l1][k], dp[j][k]+(1LL<<i));
			dp[j][l2] = min(dp[j][l2], dp[j][k]+(1LL<<i));
		}
	}

    while(ttt--) solve();

    exit(0);
}
