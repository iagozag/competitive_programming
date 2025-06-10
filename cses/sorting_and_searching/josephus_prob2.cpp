#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

void solve(){
	int n, k; cin >> n >> k;
	ord_set<int> st;
	for(int i = 1; i <= n; i++) st.insert(i);

	int pos = 0, N = n;
	for(int i = 0; i < N; i++){
		pos += (k%n), pos %= n;
		cout << *st.find_by_order(pos) << ' ';
		st.erase(*st.find_by_order(pos));
		n--;
		if(n) pos %= n;
	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
