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
	int x, y; cin >> x >> y;
	if(x == y){ cout << -1 << endl; return; }

	int k = 0;
	for(int i = 0; i < 62; i++){
		if(((x>>i)&1) and ((y>>i)&1)){
			int can = 0;
			for(int j = i-1; j >= 0; j--) if(((x>>j)&1) or ((y>>j)&1)){
				for(int l = j; l < i; l++) k += (1LL<<l), x += (1LL<<l), y += (1LL<<l);
				can = 1; break;
			}
			if(!can) k += (1LL<<i), x += (1LL<<i), y += (1LL<<i);
		}
	}

	cout << k << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
