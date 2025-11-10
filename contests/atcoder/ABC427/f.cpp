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
	int n, m; cin >> n >> m;

	const int M = m;

	int a[n]; for(int i = 0; i < n; i++) cin >> a[i];

	unordered_map<int, pair<int, int>> mp1, mp2;

	function<void(int, int, int, int, bool)> dfs = [&](int i, int lim, int mask, int sum, bool b) -> void{
		if(i > lim){

			int s = sum%M;
			if(!b){
				if(mask&(1LL<<(n/2))) mp1[s].first++;
				else mp1[s].second++;
			}
			else{
				if(mask&(1LL<<(n/2+1))) mp2[s].first++;
				else mp2[s].second++;
			}

			return;
		}

		dfs(i+1, lim, mask, sum, b);
		dfs(i+2, lim, mask|(1LL<<i), sum+a[i], b);
	};

	dfs(0, n/2, 0, 0, 0);
	dfs(n/2+1, n-1, 0, 0, 1);

	int ans = 0;
	for(auto& [k, b]: mp1){
		int need = (M-k)%M;
		auto& [x, y] = mp2[need];

		ans += b.second*(x+y) + b.first*y;
	}

	cout << ans << endl;
}


int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
