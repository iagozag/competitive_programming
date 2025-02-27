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
	vector<int> v(n); for(auto& x: v) cin >> x, --x;

	vector<bool> vis(n); int cur = 0;
	while(!vis[cur]){
		vis[cur] = 1; cur = v[cur];
	}

	for(int i = 0; i < n; i++) if(!vis[i]){ cout << "No" << endl; return; }
	cout << (cur == 0 ? "Yes" : "No") << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
