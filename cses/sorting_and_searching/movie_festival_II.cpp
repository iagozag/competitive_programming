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
	int n, k; cin >> n >> k;
	vector<pair<int, int>> v(n); 
	for(auto& [a, b]: v) cin >> a >> b;
	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b){
		if(a.second != b.second) return a.second < b.second;
		return a.first > b.first;
	});

	int ans = 0; multiset<int> st;
	for(int i = 0; i < n; i++){
		auto [a, b] = v[i];
		if(!st.empty() and *st.begin() <= a){
			auto it = st.upper_bound(a); it--;
			st.erase(it);
		}
		if((int)st.size() < k) ans++, st.insert(b);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
