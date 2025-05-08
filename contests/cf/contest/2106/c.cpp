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
	int n, k; cin >> n >> k;
	vector<int> a(n), b(n); int sum = -1;
	for(int i = 0; i < n; i++) cin >> a[i];

	bool cant = 0; int mi = INF, ma = 0;
	for(int i = 0; i < n; i++){
		cin >> b[i];
		if(b[i] != -1){
			if(sum == -1) sum = a[i]+b[i];
		}
	}

	if(sum != -1){
		for(int i = 0; i < n; i++) if(b[i] == -1) b[i] = sum-a[i];

		for(int i = 0; i < n; i++) if(a[i]+b[i] != sum or b[i] > k) cant = 1;

		if(cant){ cout << 0 << endl; return; }
		cout << 1 << endl;
		return;
	}

	for(int i = 0; i < n; i++) mi = min(mi, a[i]), ma = max(ma, a[i]);

	cout << mi+k-ma+1 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
