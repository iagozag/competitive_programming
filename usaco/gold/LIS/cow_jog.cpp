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
	vector<int> v;
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		v.emplace_back(-(a+b*t));
	}

	vector<int> dp(n+1, LINF); dp[0] = -LINF;
	for(int i = 0; i < n; i++){
		int ub = upper_bound(dp.begin(), dp.end(), v[i])-dp.begin();
		dp[ub] = v[i];
	}
	int ma = 1;
	for(int i = 2; i < n+1; i++) if(dp[i] != LINF) ma = i;
	cout << ma << endl;
}


int32_t main(){ _
    if (fopen("cowjog.in", "r")) {
		freopen("cowjog.in", "r", stdin);
		freopen("cowjog.out", "w", stdout);
	}

    int t = 1;

    while(t--) solve();

    exit(0);
}


