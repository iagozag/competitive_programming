#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	map<int, int> mp;
	for(int i = 0; i < n; i++){ int x; cin >> x; mp[x]++; }

	int ans = 1;
	for(auto [a, b]: mp) ans = ans*(b+1)%MOD;

	cout << (ans-1+MOD)%MOD << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
