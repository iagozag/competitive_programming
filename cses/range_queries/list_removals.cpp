#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;


#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;



void solve(){
	int n; cin >> n;
	ord_set<pair<int, int>> st;
	for(int i = 0; i < n; i++){ int x; cin >> x; st.insert(make_pair(i, x)); }

	for(int i = 0; i < n; i++){
		int p; cin >> p; --p;
		cout << (*st.find_by_order(p)).second << ' ';
		st.erase(*st.find_by_order(p));
	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
