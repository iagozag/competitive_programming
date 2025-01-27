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
	int n, m, d; cin >> n >> m >> d;
	vector<int> pos(n);
	for(int i = 0; i < n; i++){ int a; cin >> a; --a; pos[a] = i; }

	vector<int> a(m); for(auto& x: a) cin >> x, --x;
	int ans = INF;
	for(int i = 0; i < m-1; i++){
		if(pos[a[i]] < pos[a[i+1]] and pos[a[i+1]] <= pos[a[i]]+d){
			ans = min(ans, pos[a[i+1]]-pos[a[i]]);
			if(d < n-1) ans = min(ans, d+1-(pos[a[i+1]]-pos[a[i]]));
		}
		else ans = 0;
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
