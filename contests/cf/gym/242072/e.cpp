#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
	vector<pair<int, int>> v(n); for(auto& [a, b]: v) cin >> a >> b;
	int ans = 0; ord_set<int> st;
	for(int i = 0; i < n; i++){
		ans += (n-i+(int)st.size()-((int)st.order_of_key(v[i].first)))*v[i].second;
		st.insert(v[i].first);
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
