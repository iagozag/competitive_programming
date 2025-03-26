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
	vector<int> a(n), b(m);
	int x = 0, y = 0;
	for(auto& e: a) cin >> e, x ^= e;
	for(auto& e: b) cin >> e, y |= e;

	if(n&1){
		cout << x << ' ';
		x = 0;
		for(int i = 0; i < n; i++) a[i] |= y, x ^= a[i];
		cout << x << endl;
	} else{
		int px = x; x = 0;
		for(int i = 0; i < n; i++) a[i] |= y, x ^= a[i];
		cout << x << ' ' << px << endl;
	}
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
