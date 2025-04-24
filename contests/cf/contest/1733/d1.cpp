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
	int n, x, y; cin >> n >> x >> y;
	string a, b; cin >> a >> b;

	int ans = 0; vector<int> idx, vis;
	for(int i = 0; i < n; i++){
		if(a[i] != b[i]) idx.emplace_back(i), vis.emplace_back(0);
	}

	if(idx.size()&1){ cout << -1 << endl; return; }

	if(idx.size() == 2){
		if(idx[0] == idx[1]-1) ans += (y*2 < x ? y*2 : x);
		else ans += y;
	} else ans += (idx.size()/2)*y;

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
