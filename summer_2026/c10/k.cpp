#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 310, MOD = 1e9+7;

int n;
int g[MAX][MAX];
ld memo[MAX][MAX][MAX];
vector<pair<int, int>> v;

ld dist(int i, int j){
	int p1 = v[i].first-v[j].first, p2 = v[i].second-v[j].second;
	return sqrt(p1*p1 + p2*p2);
}

ld dp(int i, int l, int r){
	auto& p = memo[i][l][r];
	if(p != -1) return p;

	p = 0;
	if(l == r){ return p; }

	for(int j = l; j != i; j = (j+1)%n) if(g[i][j]){
		int nl = l, nr = (i-1+n)%n;
		p = max(p, dp(j, nl, nr)+dist(i, j));
	}
	for(int j = r; j != i; j = (j-1+n)%n) if(g[i][j]){
		int nl = (i+1)%n, nr = r;
		p = max(p, dp(j, nl, nr)+dist(i, j));
	}

	return p;
}

void solve(){
	cin >> n;
	v = vector<pair<int, int>>(n); for(auto& x: v) cin >> x.first >> x.second;

	memset(g, 0, sizeof g);
	int m; cin >> m;
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; g[a][b] = g[b][a] = 1; }

	for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++) for(int k = 0; k < MAX; k++) memo[i][j][k] = -1;

	ld ans = 0; 
	for(int i = 0; i < n; i++)
		ans = max(ans, dp(i, (i-n/2+n)%n, (i+(n-1)/2)%n));

	cout << fixed << setprecision(9) << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
