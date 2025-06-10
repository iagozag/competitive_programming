#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

string s;
int n, m;
vector<int> pr;
vector<vector<bool>> can;
vector<bool> memo;

bool dp(int i){
	if(i == n-1) return memo[i] = can[i][i];

	for(int j = i; j < n-1; j++) if(can[i][j]){
		memo[i] = memo[i] | dp(j+1);
		if(memo[i]) break;
	}
	memo[i] = memo[i] | can[i][n-1];

	return memo[i];
}

void solve(){
	cin >> s >> m; n = s.size();
	pr = vector<int>(m); for(auto& x: pr) cin >> x;
	can = vector<vector<bool>>(n, vector<bool>(n));

	for(int i = 0; i < n; i++){
		vector<int> sums(m);
		for(int j = i; j < n; j++){
			bool ok = 0;
			for(int k = 0; k < m; k++){
				sums[k] = sums[k]*10+(s[j]-'0'), sums[k] %= pr[k];
				ok |= (sums[k] == 0);
			}
			can[i][j] = ok;
		}
	}

	memo = vector<bool>(n);
	if(!dp(0)){ cout << -1 << endl; return; }

	vector<string> ans; string cur = ""; int last = 0;
	for(int i = 0; i < n; i++){
		cur += s[i];
		if(i == n-1 or (can[last][i] and memo[i+1])) ans.emplace_back(cur), cur = "", last = i+1;
	}

	cout << ans.size() << endl;
	for(auto& x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
