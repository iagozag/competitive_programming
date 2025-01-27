#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

bool val(int x, int l, int r){
	return l <= x and x <= r;
}

void solve(){
	int l, r; cin >> l >> r;
	int idx;
	for(int i = 30; i >= 0; i--) if((l^r)&(1<<i)){ idx = i; break; }
	int a = l|((1<<idx)-1), b = a+1;
	while(b == a or b == r) b--;
	cout << a << ' ' << b << ' ' << r << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
