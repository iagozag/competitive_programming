#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

int inv(int n){ return fexp(n, MOD-2); }

int fact[MAX];

int count(int i, int j){
	return fact[i+j]*inv(fact[i])%MOD*inv(fact[j])%MOD;
}

void solve(){
	int h, w, n; cin >> h >> w >> n;
	vector<pair<int, int>> v(n); for(auto& [a, b]: v) cin >> a >> b, --a, --b;
	v.emplace_back(h-1, w-1);
	sort(v.begin(), v.end());

	int dp[n+1]; memset(dp, 0, sizeof dp);
	for(int i = 0; i <= n; i++){
		int tot = 0;
		for(int j = i-1; j >= 0; j--) if(v[j].second <= v[i].second){
			tot += dp[j] * count(v[i].first-v[j].first, v[i].second-v[j].second), tot %= MOD;
		}
		dp[i] = (count(v[i].first, v[i].second)-tot+MOD)%MOD;
	}

	cout << dp[n] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

	fact[0] = 1;
	for(int i = 1; i < MAX; i++) fact[i] = i*fact[i-1]%MOD;

    while(ttt--) solve();

    exit(0);
}
