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
	int n, s, x; cin >> n >> s >> x;
	int l = -1, r = -1;
	vector<int> v(n), pref(n+1); int ma = -LINF;
	stack<int> st; vector<pair<int, int>> nxt(n, {-1, -1});
	for(int i = 0; i < n; i++){
		while(!st.empty() and st.top().first < v[i]) st.pop();

		if(!st.empty()) nxt[i] = st.top();
		st.push({v[i], i});

		pref[i+1] = pref[i]+v[i];
	}

	map<int, vector<int>> mp;
	for(int i = 0; i < n+1; i++) mp[pref[i]].emplace_back(i);

	int ans = 0;
	for(int i = 0; i < n; i++){
		
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
