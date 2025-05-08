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
	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector<vector<int>> next(n+1, vector<int>(k, n));
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < k; j++) next[i][j] = next[i+1][j];
		next[i][s[i]-'a'] = i;
	}

	vector<vector<int>> dp(n+1, vector<int>(k));

	vector<int> mi(n+1, INF); mi[n] = 1;
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < k; j++){
			if(next[i][j] == n) dp[i][j] = 1;
			else dp[i][j] = 1+mi[next[i][j]+1];

			mi[i] = min(mi[i], dp[i][j]);
		}
	}

	int Q; cin >> Q;
	for(int q = 0; q < Q; q++){
		string t; cin >> t; int m = t.size();

		int j = 0, cur = -1;
		for(; j < m; j++){
			cur = next[cur+1][t[j]-'a'];
			if(cur == n) break;
		}

		if(j < m){ cout << 0 << endl; continue; }

		cout << mi[cur+1] << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
