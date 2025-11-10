#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, MOD = 1e9+7;

void solve(){
	int n, k, x = 0; cin >> n >> k;

	vector<int> basis(31), a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i], x ^= a[i];
	for(int i = 0; i < n; i++){
		cin >> b[i];
		int v = a[i]^b[i];

		for(int j = 30; j >= 0; j--) v = min(v, v^basis[j]);
		
		if(v) for(int j = 30; j >= 0; j--) 
			if(!basis[j] and ((v>>j)&1)){ basis[j] = v; break; }
	}

	for(int i = 30; i >= 0; i--) x = min(x, x^basis[i]);

	if(x > k){ cout << 0 << endl; return; }

	for(int i = 30; i >= 0; i--) if(basis[i]){
		int ma = max(x, x^basis[i]);

		if(ma > k){
			for(int j = i-1; j >= 0; j--) ma = min(ma, ma^basis[j]);
		}
		if(ma <= k) x = ma;
	}

	cout << x << endl;
}

int32_t main(){ _
    if (fopen("salkan.in", "r")) {
		freopen("salkan.in", "r", stdin);
	}

    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
