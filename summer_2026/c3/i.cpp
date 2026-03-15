#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int MAX = 2e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+9;

int n;
string v[20];
int memo[39][1<<20];

int dp(int d, int mask){
	if(d == 2*n-2) return 0;

	if(memo[d][mask] != -LINF) return memo[d][mask];

	if(!(d&1)) memo[d][mask] = LINF;
	for(char c = 'a'; c <= 'z'; c++){
		int nxt = 0;
		for(int j = 0; j < n; j++) if((mask&(1<<j))){
			int i = d-j;
			if(i < 0 or i >= n) continue;

			if(i+1 < n and v[i+1][j] == c) nxt |= (1<<j);
			if(j+1 < n and v[i][j+1] == c) nxt |= (1<<(j+1));
		}

		if(!nxt) continue;

		int add = (c == 'a' ? 1 : (c == 'b' ? -1 : 0));
		if(d&1) memo[d][mask] = max(memo[d][mask], dp(d+1, nxt)+add);
		else memo[d][mask] = min(memo[d][mask], dp(d+1, nxt)+add);
	}

	return memo[d][mask];
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];

	for(int i = 0; i < 2*n-2; i++) for(int j = 0; j < (1<<n); j++) memo[i][j] = -LINF;

	int ans = (v[0][0] == 'a' ? 1 : (v[0][0] == 'b' ? -1 : 0)) + dp(0, 1);
	if(ans > 0) cout << "FIRST";
	else if(ans == 0) cout << "DRAW";
	else cout << "SECOND";
	cout << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}
