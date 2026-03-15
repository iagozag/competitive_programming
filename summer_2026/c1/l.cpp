#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2010, MOD = 1e9+7;

int n, m, k;
int v[MAX][MAX], up[MAX][MAX], down[MAX][MAX];

void update(int col){
	int x = 0;
	for(int i = 0; i < n; i++) x = (v[i][col] ? x+1 : 0), down[i][col] = x;
	x = 0;
	for(int i = n-1; i >= 0; i--) x = (v[i][col] ? x+1 : 0), up[i][col] = x;
}

int get_answer(int i){
	int l = 0, r = -1, ans = 0; deque<int> upp, downn;
	while(r < m){
		int total = -1;
		if(!upp.empty()) total += upp.front();
		if(!downn.empty()) total += downn.front();
		if(upp.empty() or downn.empty()) total++;

		while(r+1 < m and v[i][r+1] and (total == 0 or r-l < total)){
			r++;
			while(!upp.empty() and upp.back() > up[i][r]) upp.pop_back();
			upp.push_back(up[i][r]);

			while(!downn.empty() and downn.back() > down[i][r]) downn.pop_back();
			downn.push_back(down[i][r]);

			total = upp.front()+downn.front()-1;
			ans = max(ans, min(r-l+1, total));
		}

		if(!upp.empty() and up[i][l] == upp.front()) upp.pop_front();
		if(!downn.empty() and down[i][l] == downn.front()) downn.pop_front();

		l++;
		r = max(l-1, r);
	}

	// cout << "I: " << i << " = " << ans << endl;

	return ans;
}

void solve(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < m; j++) v[i][j] = (s[j] == '.');
	}

	vector<pair<int, int>> qu(k); for(auto& [a, b]: qu) cin >> a >> b, --a, --b, v[a][b] = 0;
	reverse(qu.begin(), qu.end());

	for(int j = 0; j < m; j++) update(j);

	int ans = 0; vector<int> f_ans;
	for(int i = 0; i < n; i++) ans = max(ans, get_answer(i));
	for(int q = 0; q < k; q++) {
		f_ans.emplace_back(ans);

		auto [a, b] = qu[q];
		v[a][b] = 1;
		update(b);

		ans = max(ans, get_answer(a));
	}

	reverse(f_ans.begin(), f_ans.end());
	for(auto x: f_ans) cout << x << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
