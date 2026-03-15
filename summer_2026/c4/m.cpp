#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;
const  long double pi = 2.0*acos(0);

void solve(){
	long double d, l; cin >> d >> l;

	long double h = sqrt((l/2.0)*(l/2.0)-(d/2.0)*(d/2.0)), b = l/2.0;
	cout << fixed << setprecision(3) << b*h*pi << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


