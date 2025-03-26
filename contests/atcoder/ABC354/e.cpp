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
vector<pair<int, int>> v;
vector<vector<int>> dp;

int f(bool t, int cards){
	if(dp[t][cards] != -1) return dp[t][cards];

	bool can = 0, p = !t;

	for(int i = 0; i < n; i++) if((1<<i)&cards){
		for(int j = i+1; j < n; j++) if((1<<j)&cards and (v[i].first == v[j].first or v[i].second == v[j].second)){
			can = 1;

			if(t) p |= f(!t, cards^((1<<i)|(1<<j)));
			else p &= f(!t, cards^((1<<i)|(1<<j)));
		}
	}

	return dp[t][cards] = (!can ? !t : p);
}

void solve(){
	cin >> n; v.resize(n); dp = vector<vector<int>>(2, vector<int>(1<<n, -1));
	for(auto& [a, b]: v) cin >> a >> b;

	cout << (f(true, (1<<n)-1) ? "Takahashi" : "Aoki") << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
