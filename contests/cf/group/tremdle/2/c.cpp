#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<int> v;
vector<vector<vector<int>>> dp;

int dfs(int i, int f, int x){
	if(i == n) return !f;

	int& p = dp[i][f][x];
	if(p != -1) return p;

	int y;
	if(f){
		y = 0;
		if(x == 2) y |= dfs(i, !f, x-1);
		y |= dfs(i+1, !f, v[i+1]);
	} else{
		y = 1;
		if(x == 2) y &= dfs(i, !f, x-1);
		y &= dfs(i+1, !f, v[i+1]);
	}

	return p = y;
}

void solve(){
	cin >> n;

	dp = vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>(3, -1)));
	v = vector<int>(n+1);
	for(int i = 0; i < n; i++){
		cin >> v[i]; v[i] = min(v[i], 2LL);
	}

	cout << (dfs(0, 1, v[0]) ? "First" : "Second") << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
