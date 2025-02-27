#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, x;
vector<pair<int, int>> v[3];

vector<vector<int>> f(int vit){
	int k = v[vit].size();

	vector<vector<int>> dp(k+1, vector<int>(x+1));
	for(int i = 1; i <= k; i++) for(int j = x; j >= 0; j--) 
		dp[i][j] = max(dp[i-1][j], (j >= v[vit][i-1].second ? dp[i-1][j-v[vit][i-1].second]+v[vit][i-1].first : 0));

	return dp;
}

int bs(vector<vector<int>>& dp, int vit, int need){
	int l = 0, r = x, ans = x+1;
	while(l <= r){
		int m = l+(r-l)/2;

		if(dp.back()[m] >= need) ans = m, r = m-1;
		else l = m+1;
	}

	return ans;
}

void solve(){
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		int vit, a, c; cin >> vit >> a >> c;
		v[vit-1].emplace_back(a, c);
	}

	for(int i = 0; i < 3; i++) if(!v[i].size()){ cout << 0 << endl; return; }

	vector<vector<vector<int>>> dp(3);
	for(int i = 0; i < 3; i++) dp[i] = f(i);

	int l = 0, r = 1e9, ans = 0;
	while(l <= r){
		int m = l+(r-l)/2, w = 0;
		
		for(int vit = 0; vit < 3; vit++)
			w += bs(dp[vit], vit, m);

		if(w <= x) ans = m, l = m+1;
		else r = m-1;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
