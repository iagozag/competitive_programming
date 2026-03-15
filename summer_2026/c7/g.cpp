#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	if(n == 1){ cout << 0 << endl; return; }

	int num = 2, idx = 2;
	for(int k = 0; k <= 1000000; k++){
		int l = 1, r = (n+1)/2;
		if(idx&1) idx = l+idx/2;
		else idx = r+(idx/2);

		if(num == idx){ cout << k+1 << endl; return; }
	}
}

int32_t main(){
	int ttt = 1; //cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


