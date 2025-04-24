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
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;

	int one = 0;
	for(int i = 0; i < n; i++) one += (v[i] == 1);

	if(one){ cout << n-one << endl; return; }

	int mi = LINF;
	for(int i = 0; i < n; i++){
		int g = v[i];
		for(int j = i+1; j < n; j++){
			g = __gcd(g, v[j]);
			if(g == 1){
				mi = min(mi, j-i);
				break;
			}
		}
	}

	cout << (mi == LINF ? -1 : n+mi-1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
