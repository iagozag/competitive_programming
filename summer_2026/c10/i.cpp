#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1001, MOD = 1e9+7;

int n;
int memo[MAX][MAX][3][3];

// cur number, componentes, corner blocked, mid blocked
int dp(int i, int comps, int cb, int mb){
	auto& p = memo[i][comps][cb][mb];
	if(p != -1) return p;

	p = 0;

	// added all numbers
	if(i == n) return p = (comps == 1);

	// no comp
	if(comps == 0) return p = dp(i+1, 1, 2, 0);

	// add corner comp
	if(comps >= 1) p += 2*dp(i+1, comps+1, 1, 1);

	// add mid comp
	if(comps >= 2) p += (comps-1)*dp(i+1, comps+1, 0, 2);

	// add in corner comp
	if(comps >= 1) p += (2-cb)*dp(i+1, comps, 1, 0);
	
	// add in mid comp
	if(comps >= 2) p += (2*(comps-1)-mb)*dp(i+1, comps, 0, 1);

	// join two comps
	if(comps >= 2) p += (comps-1-mb)*dp(i+1, comps-1, 0, 0);

	p %= MOD;

	return p;
}

void solve(){
	cin >> n;

	memset(memo, -1, sizeof memo);
	cout << dp(0, 0, 0, 0) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
