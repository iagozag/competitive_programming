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
	multiset<int> a;
	for(int i = 0; i < n; i++){ int x; cin >> x; a.insert(x); }

	for(int i = 0; i < m; i++){
		int q; cin >> q;
		auto it = a.upper_bound(q);
		if(it == a.begin()) cout << -1 << endl;
		else{
			it--;
			cout << *it << endl;
			a.erase(a.find(*it));
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
