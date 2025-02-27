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
	int k; cin >> k;

	int has = 0; vector<pair<int, int>> ans = {{0, 0}};

	for(int i = 1; i <= k; i++){
		if(has+i > k) break;
		ans.emplace_back(i, 0), has += i;
	}

	int line = 1;
	for(int j = 0; j <= k; j++){
		if(has == k) break;
		for(int i = 1; line <= MAX; line++, i++){
			if(has+i > k) break;
			ans.emplace_back(j, line), has += i;
		}
	}

	cout << ans.size() << endl;
	for(auto [a, b]: ans) cout << a << ' ' << b << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
