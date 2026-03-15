#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
	int n; cin >> n;
	int x = 0;
	for(int i = 0; i < n; i++){ int a; cin >> a; x ^= a; }

	cout << (x == 0 ? "second" : "first") << endl;
}

int32_t main(){
	int ttt; cin >> ttt;
	while(ttt--) solve();

	exit(0);
}
