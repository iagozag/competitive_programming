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
	int n, last, sz, ans;
	vector<int> s, len, link, lazy, qt;
	stack<stack<pair<int&, int>>> st;

	eertree(int N) {
		t = vector(N+2, vector(26, int()));
		s = len = link = lazy = qt = vector<int>(N+2);
		s[0] = -1;
		link[0] = 1, len[0] = 0, link[1] = 1, len[1] = -1;
		sz = 2, last = 0, n = 1, ans = 0;
		st.emplace();
	}

	void save(int &x) { st.top().emplace(x, x); }

	void checkpoint() { st.emplace(); }

	void rollback() {
		while(st.top().size()) {
			auto [end, val] = st.top().top(); st.top().pop();
			end = val;
		}
		st.pop();
	}

	int lead(int v){
		return s[n-len[v]-2];
	}

	void add(char c) {
		checkpoint();

		save(n), save(s[n]);
		s[n++] = c -= 'a';

		save(last);
		while (s[n-len[last]-2] != c) last = link[last];

		if (!t[last][c]) {
			int prev = link[last];
			while (s[n-len[prev]-2] != c) prev = link[prev];	

			save(link[sz]), save(len[sz]), save(t[last][c]), save(sz);

			link[sz] = t[prev][c];
			len[sz] = len[last]+2;
			t[last][c] = sz++;
		}

		save(qt[t[last][c]]);
		qt[last = t[last][c]]++;

		save(ans);
		int cur = last;
		while(cur > 1) ans++, cur = link[cur];

		save(lazy[last]);
		lazy[last]++;
	}

	void pop(){
		rollback();
	}

	int size() { return sz-2; }
};

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	eertree t(n);
	for(auto c: s){
		(c == '-') ? t.pop() : t.add(c);
		cout << t.ans << ' ';
	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

