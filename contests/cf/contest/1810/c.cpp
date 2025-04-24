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
	int n, c, d; cin >> n >> c >> d;
	set<int> st;
	vector<int> v(n); for(auto& x: v) cin >> x, st.insert(x);
	int ans = c*(n-st.size());
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	n = v.size();

	int mi = LINF;
	for(int i = 0; i < n; i++){
		mi = min(mi, d*(v[i]-i-1)+c*(n-i-1));
	}

	cout << ans+min(mi, d*(v[0] != 1)+n*c) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
