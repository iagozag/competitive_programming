#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		int l, r; cin >> l >> r; v.emplace_back(l, r);
	}

	int Q; cin >> Q;
	for(int i = 0; i < Q; i++){
		int x; cin >> x;
		for(int j = 0; j < n; j++) if(x >= v[j].first and x <= v[j].second) x++;
		cout << x << endl;
	}

}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
