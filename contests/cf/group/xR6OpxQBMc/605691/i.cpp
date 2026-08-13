#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int ans = 0;
int memo[5][5][5][5][5][5][5][5];
int v[5][5][5][5][5][5][5][5];

int dp(int a, int b, int c, int d, int e, int f, int g, int h){
	if(max({a, b, c, d, e, f, g, h}) > 4) return 0;
	if(memo[a][b][c][d][e][f][g][h] != -1) return memo[a][b][c][d][e][f][g][h];

	memo[a][b][c][d][e][f][g][h] = dp(a+1, b, c, d, e, f, g, h) |
								   dp(a, b+1, c, d, e, f, g, h) |
								   dp(a, b, c+1, d, e, f, g, h) |
								   dp(a, b, c, d+1, e, f, g, h) |
								   dp(a, b, c, d, e+1, f, g, h) |
								   dp(a, b, c, d, e, f+1, g, h) |
								   dp(a, b, c, d, e, f, g+1, h) |
								   dp(a, b, c, d, e, f, g, h+1);

	if(v[a][b][c][d][e][f][g][h] and memo[a][b][c][d][e][f][g][h]) ans++;
	return memo[a][b][c][d][e][f][g][h] |= v[a][b][c][d][e][f][g][h];
}

void solve(){
	int n, k; cin >> n >> k;
	
	fill(&memo[0][0][0][0][0][0][0][0], &memo[0][0][0][0][0][0][0][0] + (5*5*5*5*5*5*5*5), -1);
	memset(v, 0, sizeof v);

	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < 8-k; j++) s += '0';
		v[s[0]-'0'][s[1]-'0'][s[2]-'0'][s[3]-'0'][s[4]-'0'][s[5]-'0'][s[6]-'0'][s[7]-'0'] = 1;
	}

	dp(0, 0, 0, 0, 0, 0, 0, 0);

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
