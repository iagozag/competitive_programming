#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<vector<int>> g;
string s, cur;
vector<int> pi;
vector<vector<int>> memo;
int ans;

int dp(int j, int c){
	if(memo[j][c] != -1) return memo[j][c];
	if(j == 0) return memo[j][c] = 0;
	if(cur[j]-'a' == c) return memo[j][c] = j;
	return memo[j][c] = dp(pi[j-1], c);
}

void dfs(int v, int d){
	for(auto ve: g[v]){
		cur += s[ve];

		for(int i = 0; i < 26; i++) memo[d][i] = -1;

		if(d == 0) pi.emplace_back(0);
		else{
			int j = dp(pi[d-1], s[ve]-'a');
			if(cur[j] == s[ve]) j++;

			pi.emplace_back(j);
		}

		int per = d+1-pi[d];
		if(pi[d] and (d+1)%per == 0) ans = max(ans, per);
		
		dfs(ve, d+1);

		cur.pop_back(), pi.pop_back();
	}
}

void solve(){
	int n; cin >> n;
	g = vector<vector<int>>(n);
	memo = vector<vector<int>>(n, vector<int>(26));
	for(int i = 1; i < n; i++){
		int p; cin >> p; --p;
		g[p].emplace_back(i);
	}
	
	cin >> s; s = " "+s;

	ans = 0;
	dfs(0, 0);

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
