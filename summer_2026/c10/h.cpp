#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, K = 2000, MOD = 1e9+7;

void solve(){
	int n, S; cin >> n >> S;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].first;
	for(int i = 0; i < n; i++) cin >> v[i].second;
	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b){
		return a.second >= b.second;
	});

	vector<int> dp(K, -LINF); dp[0] = S;
	for(int i = 0; i < n; i++){
		for(int j = K-1; j; j--) dp[j] = max(dp[j], dp[j-1]-(v[i].first+(j-1)*v[i].second));
	}

	int ans = 0;
	for(int i = 0; i < K; i++) if(dp[i] >= 0) ans = i;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
