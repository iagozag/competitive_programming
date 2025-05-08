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
	int n; cin >> n; vector<int> v(n);
	multiset<pair<int, int>, greater<pair<int, int>>> st; priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n; i++){
		int x; cin >> x; v[i] = x;
		st.insert({x, i});
	}

	vector<int> vis(n);
	int ans = 0;
	while(!st.empty()){
		ans++;
		auto [a, b] = *st.begin(); st.erase(st.begin());
		vis[b] = 1;
		if(b and !vis[b-1]) pq.emplace(v[b-1], b-1), vis[b-1] = 1;
		if(b < n-1 and !vis[b+1]) pq.emplace(v[b+1], b+1), vis[b+1] = 1;

		while(!st.empty() and !pq.empty() and st.begin()->first == pq.top().first){
			auto [x, y] = pq.top();
			st.erase(pq.top()); pq.pop();
			vis[y] = 1;

			if(y and !vis[y-1]) pq.emplace(v[y-1], y-1), vis[y-1] = 1;
			if(y < n-1 and !vis[y+1]) pq.emplace(v[y+1], y+1), vis[y+1] = 1;

		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
