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
	int n, m; cin >> n >> m;

	int fa, fb; cin >> fa >> fb;
	int x = fa, y = fb;
	for(int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		x += a, y += b;
	}
	x += m, y += m;

	cout << (x-fa+y-fb)*2 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
