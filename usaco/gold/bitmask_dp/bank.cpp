#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<int> a, b;
vector<int> sums;
vector<vector<int>> memo;

int dp(int i, int j){
	int& p = memo[i][j];
	if(p != -1) return p;

	if(i == n) return p = 1;

	p = 0;
	for(int k = j; k; k = (k-1)&j) if(sums[k] == a[i] and dp(i+1, k^j))
		return p = 1;

	return p;
}

void solve(){
	cin >> n >> m;
	a.resize(n), b.resize(m);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	if(n > m){ cout << "NO" << endl; return; }
	if(n == m){
		sort(a.begin(), a.end()), sort(b.begin(), b.end());
		cout << (a == b ? "YES" : "NO") << endl;
		return;
	}

	sums = vector<int>(1<<m);
	for(int i = 0; i < (1<<m); i++) for(int j = 0; j < m; j++) if(i&(1<<j)) sums[i] = sums[i^(1<<j)]+b[j];

	memo = vector<vector<int>>(n+1, vector<int>(1<<m, -1));
	cout << (dp(0, (1<<m)-1) ? "YES" : "NO") << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
