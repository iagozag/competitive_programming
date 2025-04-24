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
	int x; cin >> x;

	if(x&1){ cout << -1 << endl; return; }

	int a = x, b = 0;

	vector<int> sums;
	for(int i = 32; i >= 0; i--) if(!((x>>i)&1)) sums.emplace_back(1LL<<i);

	x /= 2;

	for(auto y: sums) if(x >= y){
		a += y, b += y, x -= y;
	}


	if(x) cout << -1 << endl;
	else cout << a << ' ' << b << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
