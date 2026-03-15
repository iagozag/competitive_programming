#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int MAX = 2e5+10, LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
	int n; cin >> n;
	cout << (n%3 == 1 or n%3 == 2 ? "First" : "Second") << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;
	while(ttt--) solve();

	exit(0);
}
