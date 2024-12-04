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
	map<int, int> mp; for(int i = 0; i < n; i++){ int a; cin >> a; mp[a]++; }

	int ans = n, sec = false;
	for(int i = 0; i < n; i++){
		if(mp[i] == 0) ans = min(ans, i);
		else if(mp[i] == 1){
			if(!sec) sec = 1;
			else ans = min(ans, i);
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
