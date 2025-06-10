#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int seg[2 * MAX];
int n;

void build() {
	for (int i = n - 1; i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);
}

int query(int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = max(ret, seg[a]);
		if (b % 2 == 0) ret = max(ret, seg[b]);
	}
	return ret;
}

void solve(){
	cin >> n;
	vector<int> v(n); map<int, vector<int>> pos;
	for(int i = 0; i < n; i++) cin >> v[i], pos[v[i]].emplace_back(i), seg[i+n] = v[i];

	build();

	vector<int> nxtl(n), nxtr(n);
	stack<pair<int, int>> st;
	for(int i = 0; i < n; i++){
		while(!st.empty() and st.top().first < v[i]) st.pop();
		nxtl[i] = (st.size() ? st.top().second : -1);
		st.push({v[i], i});
	}
	st = {};
	for(int i = n-1; i >= 0; i--){
		while(!st.empty() and st.top().first < v[i]) st.pop();
		nxtr[i] = (st.size() ? st.top().second : -1);
		st.push({v[i], i});
	}

	vector<int> memo(n, -1);
	auto dp = [&](auto&& self, int i) -> int {
		if(memo[i] != -1) return memo[i];

		int best = 0;

		// left
		int l = (nxtl[i] == -1 ? 0 : nxtl[i]+1);
		if(l <= i-1){
			int ml = query(l, i-1);
			int lb = lower_bound(pos[ml].begin(), pos[ml].end(), l)-pos[ml].begin();
			for(int j = lb; j < (int)pos[ml].size() and pos[ml][j] <= i; j++) best = max(best, self(self, pos[ml][j]));
		}

		// right
		int r = (nxtr[i] == -1 ? n-1 : nxtr[i]-1);
		if(i+1 <= r){
			int mr = query(i+1, r);
			int lb = lower_bound(pos[mr].begin(), pos[mr].end(), i)-pos[mr].begin();
			for(int j = lb; j < (int)pos[mr].size() and pos[mr][j] <= r; j++) best = max(best, self(self, pos[mr][j]));
		}

		return memo[i] = 1+best;
	};

	int ans = 0, ma = *max_element(v.begin(), v.end());
	for(auto i: pos[ma]) ans = max(ans, dp(dp, i));
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
