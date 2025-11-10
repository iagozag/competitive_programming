#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
const int MAX = 2e5+10, MOD = 1e9+7;
 
struct eertree {
	vector<vector<int>> t;
	int n, last, sz;
	vector<int> s, len, link, quick, qt;
	stack<stack<pair<int&, int>>> st;
 
	eertree(int N) {
		t = vector(N+2, vector(26, int()));
		s = len = link = quick = qt = vector<int>(N+2);
		s[0] = -1;
		link[0] = 1, len[0] = 0, link[1] = 1, len[1] = -1;
		sz = 2, last = 0, n = 1;
		st.emplace();
	}
 
	void save(int &x) { st.top().emplace(x, x); }
 
	void checkpoint() { st.emplace(); }
 
	void pop() {
		while(st.top().size()) {
			auto [end, val] = st.top().top(); st.top().pop();
			end = val;
		}
		st.pop();
	}
 
	int lead(int v){
		return s[n-len[v]-2];
	}
 
	int add(char c) {
		s[n++] = c -= 'a';
 
		while (1){
			if(lead(last) == c) break;
			if(lead(link[last]) == c){ last = link[last]; break; }
 
			last = quick[last];
		}
 
		int ans = len[last]+2;
 
		if (!t[last][c]) {
			int prev = link[last];
			while (lead(prev) != c) prev = link[prev];
 
			save(link[sz]), save(quick[sz]), save(len[sz]), save(t[last][c]);
			link[sz] = t[prev][c];
			quick[sz] = (lead(prev) == lead(link[prev]) ? quick[prev] : link[prev]);
			len[sz] = len[last]+2;
			t[last][c] = sz++;
		}
 
		save(qt[t[last][c]]);
		qt[last = t[last][c]]++;
 
		checkpoint();
		return ans;
	}
 
	int size() { return sz-2; }
 
	ll propagate() {
		ll ret = 0;
		for (int i = n; i > 1; i--) {
			qt[link[i]] += qt[i];
			ret += qt[i];
		}
		return ret;
	}
};
 
void solve(){
	string s; cin >> s;
	eertree et(s.size());
	for(auto c: s) cout << et.add(c) << ' ';
	cout << endl;
}
 
int32_t main(){ _
    int ttt = 1; // cin >> ttt;
 
    while(ttt--) solve();
 
    exit(0);
}
