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
vector<vector<int>> v;
vector<int> a, b;

vector<vector<int>> memo;

int dp(int i, int op){
	int& p = memo[i][op];
	if(p != LINF) return p;

	if(i == n-1) return p = op*a[i];

	int has = 0, can = 1;
	for(int j = 0; j < n; j++){
		if(v[i][j]+op == v[i+1][j]) has = 1;
		else if(v[i][j]+op == v[i+1][j]+1) can = 0;
	}

	if(has and !can) return p = LINF-1;
	else if(has) return p = op*a[i]+dp(i+1, 1);
	else if(!can) return p = op*a[i]+dp(i+1, 0);
	return p = op*a[i]+min(dp(i+1, 0), dp(i+1, 1));
}

void solve(){
	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));
	for(auto& x: v) for(auto& y: x) cin >> y;

	a = b = vector<int>(n);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	memo = vector<vector<int>>(n, vector<int>(2, LINF));
	int ans = min(dp(0, 0), dp(0, 1));

	for(int i = 0; i < n; i++) for(int j = 0; j < i; j++) swap(v[i][j], v[j][i]);

	memo = vector<vector<int>>(n, vector<int>(2, LINF));
	a = b;
	ans += min(dp(0, 0), dp(0, 1));

	cout << (ans > 1e15 ? -1 : ans) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
