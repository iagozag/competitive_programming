#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1501, MOD = 1e9+7;


void solve(){
	int n; cin >> n; vector<pair<int, int>> v(n);

	vector<int> s(3);
	for(auto& x: v) cin >> x.first >> x.second, x.first--, s[x.first] += x.second;

	int sum = s[0]+s[1]+s[2];
	if(sum%3){ cout << -1 << endl; return; }

	vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(sum+1, vector<int>(sum+1, INF)));
	memo[0][s[0]][s[1]] = 0;

	for(int i = 1; i <= n; i++) for(int a = 0; a <= sum; a++) for(int b = 0; b <= sum; b++){
		memo[i][a][b] = min(memo[i][a][b], memo[i-1][a][b]);

		if(memo[i][a][b] > n) continue;

		for(int j = 0; j < 3; j++) if(j != v[i-1].first){
			int na = a, nb = b;
			if(j == 0) na += v[i-1].second;
			if(j == 1) nb += v[i-1].second;
			if(v[i-1].first == 0) na -= v[i-1].second;
			if(v[i-1].first == 1) nb -= v[i-1].second;

			if(na >= 0 and nb >= 0 and na <= sum and nb <= sum)
				memo[i][na][nb] = min(memo[i][na][nb], memo[i-1][a][b]+1);				
		}
	}

	int& ans = memo[n][sum/3][sum/3];
	cout << (ans > n ? -1 : ans) << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
