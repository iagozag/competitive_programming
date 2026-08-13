#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> s, t;
vector<array<int, 2>> nxts, nxtt;
vector<vector<array<int, 2>>> memo;
int n, m;

int dp(int i, int j, int k){
	if(i == n+1 and j == m+1) return 0;
	if(memo[i][j][k] != -1) return memo[i][j][k];

	return memo[i][j][k] = 1+min(dp(nxts[i][k], nxtt[j][k], 0), dp(nxts[i][k], nxtt[j][k], 1));
}

void rec(int i, int j, int k, string& ans){
	if(i == n+1 and j == m+1) return;

	ans += char(k+'0');
	if(memo[i][j][k] == 1+memo[nxts[i][k]][nxtt[j][k]][0]) rec(nxts[i][k], nxtt[j][k], 0, ans);
	else rec(nxts[i][k], nxtt[j][k], 1, ans);
}

void solve(){
	string a, b; cin >> a >> b;
	for(auto c: a) s.emplace_back(c-'0');
	for(auto c: b) t.emplace_back(c-'0');

	n = s.size(), m = t.size();
	nxts = vector<array<int, 2>>(n+2, {n+1, n+1});
	nxtt = vector<array<int, 2>>(m+2, {m+1, m+1});

	int last0 = n+1, last1 = n+1;
	for(int i = n-1; i >= 0; i--){
		if(s[i] == 0) last0 = i+1;
		if(s[i] == 1) last1 = i+1;
		nxts[i][0] = last0;
		nxts[i][1] = last1;
	}
	last0 = last1 = m+1;
	for(int i = m-1; i >= 0; i--){
		if(t[i] == 0) last0 = i+1;
		if(t[i] == 1) last1 = i+1;
		nxtt[i][0] = last0;
		nxtt[i][1] = last1;
	}
	
	memo = vector<vector<array<int, 2>>>(n+2, vector<array<int, 2>>(m+2, {-1, -1}));
	dp(0, 0, 0), dp(0, 0, 1);

	string ans = "";
	rec(0, 0, memo[0][0][0] > memo[0][0][1], ans);

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
