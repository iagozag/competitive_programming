#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10, MOD = 1e9+7;

int n, q;
int bit[MAX+10];

void update(int i, int x){
	for(i++; i <= MAX; i += i&-i) bit[i] += x;
}

int pref(int i){
	int ans = 0;
	for(i++; i; i -= i&-i) ans += bit[i];
	return ans;
}

int query(int l, int r){
	return pref(r)-pref(l-1);
}

void solve(){
	cin >> n >> q;
	vector<vector<int>> v(MAX);
	for(int i = 0; i < n; i++){ int a, b; cin >> a >> b; v[a].emplace_back(b); }

	vector<vector<int>> qu(q);
	set<pair<int, int>> st;
	for(int i = 0; i < q; i++){
		qu[i].emplace_back(0);

		int m; cin >> m;
		for(int j = 0; j < m; j++){ int x; cin >> x; qu[i].emplace_back(x); }

		qu[i].emplace_back(MAX);
	}

	vector<vector<pair<int, int>>> queries(MAX);
	for(int i = 0; i < q; i++){
		for(int j = 1; j < (int)qu[i].size(); j++){
			int a = qu[i][j-1]+1, b = qu[i][j]-1;
			if(a <= b) queries[a].emplace_back(b, i);
		}
	}

	vector<int> ans(q);
	for(int i = MAX-1; i; i--){
		for(auto b: v[i])
			update(b, 1);

		for(auto [b, idx]: queries[i]) ans[idx] += query(i, b);
	}
	
	for(int i = 0; i < q; i++){
		cout << n-ans[i] << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
