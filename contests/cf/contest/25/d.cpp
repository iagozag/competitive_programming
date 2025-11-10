#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1010, MOD = 1e9+7;

vector<int> id(MAX), sz(MAX, 1);
set<int> st;

int find(int x){
	return id[x] = (id[x] == x ? x : find(id[x]));
}

bool unio(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return false;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b], id[b] = a;
	return true;
}

void solve(){
	int n; cin >> n;
	vector<pair<int, int>> edges(n-1);
	for(auto& [a, b]: edges) cin >> a >> b;

	iota(id.begin(), id.end(), 0);
	queue<pair<int, int>> rem;
	for(auto [a, b]: edges){
		if(!unio(a, b)) rem.push({a, b});
	}

	for(int i = 1; i <= n; i++) st.insert(find(i));

	vector<pair<pair<int, int>, pair<int, int>>> ans;
	while(st.size() > 1){
		auto it = st.begin(), it2 = st.begin(); it2++;
		auto [a, b] = rem.front(); rem.pop();
		ans.push_back({{a, b}, {*it, *it2}});
		st.erase(it2);
	}

	cout << ans.size() << endl;
	for(auto [a, b]: ans) cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
