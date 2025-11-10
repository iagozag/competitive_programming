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
	vector<vector<int>> pos(n);
	for(int i = 0; i < n; i++){
		int x; cin >> x; --x;
		pos[x].emplace_back(i);
	}

	int ans = 0;
	for(int i = 0; i < n-1; i++){
		while(!pos[i].empty()){
			int x = pos[i].back(); pos[i].pop_back();
			if(!pos[i+1].empty() and pos[i+1].back() > x) ans++, pos[i+1].pop_back();
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

