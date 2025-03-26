#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){
	cout << 0 << endl;
}

void solve(){
	int n; cin >> n;
	map<int, int> mp; int ans = 0;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		mp[x]++;
		if(ans == 0 and mp[0] >= 3 and mp[1] >= 1 and mp[2] >= 2 and mp[3] >= 1 and mp[5] >= 1){
			ans = i+1;
		}
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
