#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

string a, b, c;
int n, m;
int memo[2000][2000];

int dp(int i, int j){
	if(i == n and j == m) return 0;
	if(i > n or j > m) return INF;
	if(memo[i][j] != -1) return memo[i][j];

	memo[i][j] = INF;
	return memo[i][j] = min(dp(i+1, j)+(c[i+j] != a[i]), dp(i, j+1)+(c[i+j] != b[j]));
}

void solve(){
	cin >> a >> b >> c;
	n = a.size(), m = b.size();
	memset(memo, -1, sizeof memo);
	cout << dp(0, 0) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
