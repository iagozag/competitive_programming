#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define int long long

const int INF = 0x3f3f3f3f;

int32_t main(){ _
	int N, T; cin >> N >> T;
	vector<vector<pair<int, int>>> cent(T);
	for(int i = 0; i < N; i++){
		int k, t, m; cin >> k >> t >> m; t--;
		cent[t].emplace_back(k/2, m);
	}

	int ans = 0;
	for(int i = 0; i < T; i++){
		int cap, b; cin >> cap >> b;
		cap = min(cap, b);
	
		int dp[cap+1]; memset(dp, 0, sizeof dp);
		for(auto [pes, majest]: cent[i]){
			for(int j = cap; j >= pes; j--) dp[j] = max(dp[j], dp[j-pes]+majest);
		}
		
		ans += dp[cap];
	}

	cout << ans << endl;

	exit(0);

}
