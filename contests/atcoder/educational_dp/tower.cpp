#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e4+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<tuple<int, int, int>> t;
	for(int i = 0; i < n; i++){
		int w, s, v; cin >> w >> s >> v;
		t.emplace_back(w, s, v);
	}
	sort(t.begin(), t.end(), [&](tuple<int, int, int> i, tuple<int, int, int> j){
		auto [wi, si, vi] = i;
		auto [wj, sj, vj] = j;
		return wi+si > wj+sj;
	});

	vector<vector<int>> dp(n, vector<int>(MAX)); dp[0][get<1>(t[0])] = get<2>(t[0]);
	for(int i = 1; i < n; i++){
		auto [wi, si, vi] = t[i];
		for(int j = MAX-wi-1; j >= 0; j--){
			dp[i][j] = max({dp[i][j], dp[i][j+1], dp[i-1][j]});

			if(j == si) dp[i][j] = max(dp[i][j], vi);

			dp[i][min(si, j)] = max(dp[i][min(si, j)], dp[i-1][j+wi]+vi);
		}
	}

	int ans = 0;
	for(int i = 0; i < MAX; i++) ans = max(ans, dp[n-1][i]);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
