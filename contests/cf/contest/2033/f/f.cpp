#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	ll n, k; cin >> n >> k; n %= MOD;
	if(k == 1){ cout << n << endl; return; }

	ll a = 0, b = 1, c = 1; int idx = 2;
	while(c){
		idx++, a = b, b = c, c = (a+b)%k;
	}

	cout << idx*n%MOD << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
