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
	int n; cin >> n;
	int a[n], b[n]; set<int> st;
	for(int i = 0; i < n; i++) cin >> a[i], st.insert(a[i]);
	for(int i = 0; i < n; i++) cin >> b[i], st.insert(b[i]);
	
	int ans = 2;
	for(int i = 1; i < n; i++){
		int mi = min(a[i], b[i]), ma = max(a[i], b[i]);
		int pmi = min(a[i-1], b[i-1]), pma = max(a[i-1], b[i-1]);

		if(mi >= pma) ans *= 2, ans %= MOD;
	}
	
	cout << ans%MOD << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
