#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

int32_t main(){ _
	int n; cin >> n;
	set<string> st;
	vector<pair<string, string>> edges(n);
	for(auto& [a, b]: edges) cin >> a >> b, st.insert(a), st.insert(b);

	map<string, int> mp; map<int, string> mp_r; int k = 0;
	for(auto s: st) mp[s] = k, mp_r[k++] = s;

	vector<int> g(n); vector<int> in(n), out(n);
	for(auto [a, b]: edges){
		int p1 = mp[a], p2 = mp[b];
		g[p1] = p2;
		in[p2]++, out[p1++];
	}

	int qnt = 0;
	for(int i = 0; i < n; i++) qnt += (in[i] == 0);

	vector<int> ans;
	for(int i = 0; i < n; i++) if(in[i] == 1 and in[g[i]] == 2){
		if(qnt == 1) ans.emplace_back(i);
	}

	cout << ans.size() << endl;
	vector<string> final_ans;
	for(auto x: ans) final_ans.emplace_back(mp_r[x]);
	sort(final_ans.begin(), final_ans.end());
	for(auto x: final_ans) cout << x << endl;

	exit(0);
}
