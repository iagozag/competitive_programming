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
	int n, m; cin >> n >> m;
	vector<int> v(n);

	for(int i = 0; i < m; i++){
		int p, c, k; cin >> p >> c >> k; --p;
		v[p] += k*c;
		for(int j = 0; j < k; j++){
			int a; cin >> a; --a;
			v[a] -= c;
		}
	}

	vector<int> sums(1<<n);
	for(int i = 0; i < (1<<n); i++){
		int s = 0;
		for(int j = 0; j < n; j++) if(i&(1<<j)) s += v[j];
		sums[i] = s;
	}

	vector<int> dp(1<<n, -LINF); dp[0] = 0;
	for(int i = 1; i < (1<<n); i++){
		for(int j = i; j; j = (j-1)&i) if(sums[i^j] == 0)
			dp[i] = max(dp[i], dp[i^j]+1);
	}

	cout << n-dp.back() << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
