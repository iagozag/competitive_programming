#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define int long long

const int INF = 0x3f3f3f3f, MOD = 998244353;

int32_t main(){ _
	int n, ans = 1; cin >> n;

	bool ok = 0; vector<int> vis(1e5+1);
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		int g = __gcd(a, b);
		a /= g, b /= g;

		if(b != 1) ok = 1;

		for(int j = 1; j <= sqrt(b); j++) if(b%j == 0) vis[j] = 1, vis[b/j] = 1;
	}

	vector<int> pr(1e5+1, 1);
	for(int i = 2; i <= 1e5; i++) if(pr[i]){
		if(vis[i]) ans = ans*i%MOD;
		for(int j = i*i; j <= 1e5; j += i) pr[j] = 0;
	}

	cout << (ok ? ans : 2) << endl;

	exit(0);

}
