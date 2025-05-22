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
	vector<int> v(MAX);
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b; b /= __gcd(a, b);
		for(int j = 2; j <= b/j; j++) if(b%j == 0){
			v[j] = 1;
			while(b%j == 0) b /= j;
		}
		if(b > 1) v[b] = 1;
	}

	if(accumulate(v.begin(), v.end(), 0ll) == 0){ cout << 2 << endl; return; }
	int ans = 1;
	for(int i = 2; i < MAX; i++) if(v[i]) ans = ans*i%MOD;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
