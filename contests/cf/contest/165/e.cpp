#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1<<22, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> v(MAX), a;
	for(int i = 0; i < n; i++){ int x; cin >> x; v[x]++, a.emplace_back(x); }

	vector<int> dp(MAX, -1);
	for(int i = 1; i < MAX; i++){
		if(dp[i] == -1 and v[i]) dp[i] = i;

		for(int j = 0; j < 22; j++) if((i&(1<<j)) == 0){
			int num = i|(1<<j);
			if(num >= MAX) continue;
			if(dp[num] == -1 and dp[i] != -1) dp[num] = dp[i];
		}
	}

	for(auto x: a){
		int need = ((1<<22)-1)^x;
		cout << ((need < MAX and dp[need] != x) ? dp[need] : -1) << ' ';
	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
