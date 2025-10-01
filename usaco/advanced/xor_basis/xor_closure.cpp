#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int basis[64], sz = 0;

void insert_basis(int mask){
	for(int i = 0; i < 64; i++){
		if(!(mask&(1LL<<i))) continue;
		if(!basis[i]){
			basis[i] = mask;
			sz++;
			return;
		}
		mask ^= basis[i];
	}
}

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x, insert_basis(x);

	cout << (1LL<<sz)-n << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
