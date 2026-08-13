#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

void solve(){
	int pot[MAX]; pot[0] = 1;
	for(int i = 1; i < MAX; i++) pot[i] = pot[i-1]*2%MOD;

	int n; cin >> n;
	vector<vector<int>> v(n+1); int l = 1, r = n;
	for(int i = 0; i < n; i++){ 
		int a, b; cin >> a >> b; 
		v[a].emplace_back(b); 
		l = max(l, a), r = min(r, b);
	}

	int ans = 0, qnt = 0;
	vector<int> sum(n+1);
	for(int i = 1; i <= n-i and i <= r and n-i >= l; i++){
		int a = i, b = n-i;

		for(auto j: v[a]){
			if(j <= n-i) sum[j]++;
			else qnt++;
		}

		qnt += sum[n-i];
		ans += pot[qnt], ans %= MOD;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
