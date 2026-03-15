#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int a, b; cin >> a >> b;

	int mi_num = a/b, ma_num = a-b+1;

	int mi = 0, rem = a%b;
	mi = mi_num*(mi_num-1)/2*(b-rem);
	mi_num++;
	mi += mi_num*(mi_num-1)/2*rem;

	cout << mi << ' ' << ma_num*(ma_num-1)/2 << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


