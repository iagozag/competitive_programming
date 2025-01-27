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
	int n, d; cin >> n >> d;
	cout << 1 << ' ';
	if(d%3 == 0 or n > 2) cout << 3 << ' ';
	if(d == 5) cout << 5 << ' ';
	if(n >= 3 or d == 7) cout << 7 << ' ';
	if(d == 9 or (d%3 == 0 and n > 2 and n <= 5) or n > 5) cout << 9 << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
