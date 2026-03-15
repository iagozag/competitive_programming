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
	int d, k; cin >> d >> k;
	int l = 0, r = 1e5, ans = l;
	while(l <= r){
		int m = l+(r-l)/2;
		if(m*k <= d*d and m*k*m <= d*d and m*k*m*k <= d*d and m*k*m*k*2ll <= d*d) ans = m, l = m+1;
		else r = m-1;
	}

	if((ans+1)*k <= d*d and (ans+1)*k*(ans+1)*k <= d*d and ans*k*ans*k + (ans+1)*k*(ans+1)*k <= d*d) cout << "Ashish" << endl;
	else cout << "Utkarsh" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
