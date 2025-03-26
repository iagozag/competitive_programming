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
	int n, x = -1, y; cin >> n;
	for(y = 1; y <= 1e7; y++){
		int have = n+y*y*y;
		int cb = cbrt(have);
		if(cb*cb*cb == have){
			x = cb;
			break;
		}
	}

	if(x == -1){ cout << -1 << endl; return; }
	cout << x << ' ' << y << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
