#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> nto3(int n){
	vector<int> base(20);
	for(int i = 0; i < 20; i++) base[i] = n%3, n /= 3;
	return base;
}

void solve(){
	int n, k; cin >> n >> k;
	int pot[20]; pot[0] = 1;
	for(int i = 1; i < 20; i++) pot[i] = pot[i-1]*3;

	int ans = 0;
	for(int i = 19; i; i--){
		int l = 0, r = n, qnt = 0;
		while(l <= r){
			int m = l+(r-l)/2;

		}

		ans += qnt*(pot[i-1]*(i+9)), k -= qnt;
		
	}
	if(k < 0){ cout << -1 << endl; return; }

	if(n) ans += 3*n;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
