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
	int n, q; cin >> n >> q;
	vector<pair<int, int>> qu;
	for(int i = 0; i < q; i++){ int a, b; cin >> a >> b; --b; qu.emplace_back(a, b); }

	set<int> r, c;
	ord_set<pair<int, int>> row;
	ord_set<pair<int, int>> col;

	int ans = 0;
	vector<int> lastc(n, -1), lastr(n, -1);
	for(int i = 0; i < q; i++){
		auto [op, x] = qu[i];

		if(op == 1){
			if(!r.count(x)) ans += n;
			else{
				row.erase(make_pair(lastr[x], x));
				ans += col.size() - col.order_of_key(make_pair(lastr[x], 0)); // qnt in range not repeated
			}
			row.insert(make_pair(i, x)), r.insert(x);
			lastr[x] = i;
		} else{
			if(!c.count(x)) ans -= row.size();
			else{
				col.erase(make_pair(lastc[x], x));
				ans -= row.size() - row.order_of_key(make_pair(lastc[x], 0)); // qnt in range not repeated
			}
			col.insert(make_pair(i, x)), c.insert(x);
			lastc[x] = i;
		}

		cout << ans << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
