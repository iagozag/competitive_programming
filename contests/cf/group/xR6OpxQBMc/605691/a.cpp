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
	vector<int> can = {1, 0, 0, 1, 1, 1, 1};
	int ans = 0;
	int j = 0;
	for(int i = 0; i < n; i++){
		ans += can[j];
		j = (j+1)%7;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

