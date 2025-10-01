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

const int MAX = 4e5+10, MOD = 1e9+7;



void solve(){
	int N, q; cin >> N >> q;
	ord_set<pair<int, int>> st;
	vector<int> v(N); for(int i = 0; i < N; i++) cin >> v[i], st.insert({v[i], i});

	vector<tuple<int, int, int>> qu;
	for(int i = 0; i < q; i++){
		char c; int a, b; cin >> c >> a >> b;
		if(c == '!'){ 
			--a; 
			st.erase({v[a], a});
			st.insert({b, a});
			v[a] = b;
		}
		else{ 
			cout << st.order_of_key({b+1, -INF})-st.order_of_key({a, -INF}) << endl;
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
