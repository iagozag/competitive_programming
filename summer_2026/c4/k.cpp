#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
	long double r, c; cin >> r >> c;
	long double area = pi*r*r, area2 = pi*(r-c)*(r-c);
	cout << fixed << setprecision(12) << (area2/area)*100.0 << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;
	while(ttt--) solve();

	exit(0);
}

