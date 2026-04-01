#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
	int n, m, K; cin >> n >> m >> K;
	vector<string> s(n); for(auto& x: s) cin >> x;
	vector<int> w(n); int sum = 0;
	set<int> st;
	for(int i = 0; i < n; i++){
		int r = uniform(1, MOD-1);
		while(st.count(r)) r = uniform(1, MOD-1);
		w[i] = r, sum += w[i], sum %= MOD;
		st.insert(r);
	}

	vector<vector<int>> pref(m, vector<int>(4));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		if(s[i][j] == 'A') pref[j][0] += w[i];
		else if(s[i][j] == 'C') pref[j][1] += w[i];
		else if(s[i][j] == 'G') pref[j][2] += w[i];
		else if(s[i][j] == 'T') pref[j][3] += w[i];
	}

	for(int i = 0; i < n; i++){
 		int need = ((sum-w[i])*K%MOD)+MOD; need %= MOD;

		int diff = 0;
		for(int j = 0; j < m; j++){
			for(int k = 0; k < 4; k++) diff += pref[j][k];

			if(s[i][j] == 'A') diff -= pref[j][0];
			else if(s[i][j] == 'C') diff -= pref[j][1];
			else if(s[i][j] == 'G') diff -= pref[j][2];
			else if(s[i][j] == 'T') diff -= pref[j][3];

			diff %= MOD, diff += MOD, diff %= MOD;
		}

		if(diff == need){ cout << i+1 << endl; return; }
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
