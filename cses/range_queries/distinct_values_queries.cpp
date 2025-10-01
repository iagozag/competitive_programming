#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> last;

void solve(){
	int n, q; cin >> n >> q; int k = 0;
	const int B = sqrt(n);

	set<int> st; vector<int> v(n);
	for(int i = 0; i < n; i++){ cin >> v[i]; st.insert(v[i]); }

	map<int, int> mp;
	for(auto x: st) mp[x] = k++;

	vector<int> qnt(MAX);
	for(int i = 0; i < n; i++) v[i] = mp[v[i]];

	vector<pair<pair<int, int>, int>> qu(q); 
	for(int i = 0; i < q; i++){ int a, b; cin >> a >> b; --a, --b; qu[i] = {{a, b}, i}; }
	sort(qu.begin(), qu.end(), [&](pair<pair<int, int>, int> q1, pair<pair<int, int>, int> q2){
		auto [x, idx] = q1;
		auto [a, b] = x;
		auto [y, idy] = q2;
		auto [c, d] = y;
		
		if(a/B != c/B) return a/B < c/B;
		return ((a/B)&1 ? b > d : b < d);
	});

	int f = 0;

	auto insert = [&](int i){
		qnt[i]++;
		if(qnt[i] == 1) f++;
	};

	auto erase = [&](int i){
		qnt[i]--;
		if(qnt[i] == 0) f--;
	};
	
	vector<int> ans(q);

	int l = 0, r = -1;
	for(int i = 0; i < q; i++){
		auto [x, id] = qu[i];
		auto [a, b] = x;
		while(r < b) insert(v[++r]);
		while(l > a) insert(v[--l]);
		while(l < a) erase(v[l++]);
		while(r > b) erase(v[r--]);

		ans[id] = f;
	}

	for(auto x: ans) cout << x << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
