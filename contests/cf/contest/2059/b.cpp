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
	int n, k; cin >> n >> k;
	vector<int> v(n); for(auto& x: v) cin >> x;
	if(k == n){
		for(int i = 1; i < n; i+=2) if(v[i] != (i+1)/2){ cout << (i+1)/2 << endl; return; }
		cout << n/2+1 << endl;
	} else{
		for(int i = 1; i < n-k+2; i++) if(v[i] != 1){ cout << 1 << endl; return; }
		cout << 2 << endl;
	}
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
