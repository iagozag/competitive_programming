#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, t; cin >> n >> t;
	int v[n][t];
	for(int i = 0; i < n; i++) for(int j = 0; j < t; j++) cin >> v[i][j];

	vector<vector<int>> pref(n, vector<int>(t+1));
	for(int i = 0; i < n; i++) for(int j = 1; j <= t; j++) pref[i][j] = pref[i][j-1]+v[i][j-1];

	auto sum = [&](int i, int l, int r) -> int{
		return pref[i][r+1]-pref[i][l];
	};

	int L, U; cin >> L >> U;

	int dp[n][t+1]; for(int i = 0; i < n; i++) for(int j = 0; j <= t; j++) dp[i][j] = -LINF;
	pair<pair<int, int>, pair<int, int>> best[t+1]; for(int i = 0; i <= t; i++) best[i] = {{-LINF, -1}, {-LINF, -1}};

	for(int i = 0; i < n; i++) dp[i][0] = 0;
	best[0] = {{0, 0}, {0, 1}};

	for(int j = L; j <= t; j++){
		for(int i = 0; i < n; i++){
			for(int k = j-L; k >= max(0LL, j-U); k--){
				auto p = best[k];
				auto [a, b] = p.first;
				auto [c, d] = p.second;
				dp[i][j] = max(dp[i][j], sum(i, k, j-1) + (b == i ? c : a));
			}

			if(dp[i][j] > best[j].first.first) best[j].second = best[j].first, best[j].first = {dp[i][j], i};
			else if(dp[i][j] > best[j].second.first) best[j].second = {dp[i][j], i};
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, dp[i][t]);
	cout << (ans ? ans : -1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
