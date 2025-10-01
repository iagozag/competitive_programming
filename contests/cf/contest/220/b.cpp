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
	int n, q; cin >> n >> q;
	const int B = sqrt(n);

	vector<int> v(n); for(auto& x: v) cin >> x;

	int id = 0;
	vector<tuple<int, int, int>> qu(q); for(auto& [a, b, idx]: qu) cin >> a >> b, --a, --b, idx = id++;

	sort(qu.begin(), qu.end(), [&](const tuple<int, int, int>& x, const tuple<int, int, int>& y){
		auto [a1, b1, id1] = x;
		auto [a2, b2, id2] = y;
		int d1 = a1/B, d2 = a2/B;
		if(d1 != d2) return d1 < d2;

		return (d1&1 ? (b1 > b2) : (b1 < b2));
	});

	vector<int> mp(n+1); int ans = 0;
	vector<int> final_ans(q);

	auto add = [&](int x) -> void{
		if(x > n) return;
		if(mp[x] == x) ans--;
		else if(mp[x]+1 == x) ans++;
		mp[x]++;
	};
	
	auto rem = [&](int x) -> void{
		if(x > n) return;
		if(mp[x] == x) ans--;
		else if(mp[x]-1 == x) ans++;
		mp[x]--;
	};

	int l = 0, r = -1;
	for(auto [a, b, idx]: qu){
		while(l > a) l--, add(v[l]);
		while(r < b) r++, add(v[r]);
		while(l < a) rem(v[l++]);
		while(r > b) rem(v[r--]);

		final_ans[idx] = ans;
	}

	for(auto x: final_ans) cout << x << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
