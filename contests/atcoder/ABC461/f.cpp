#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

void solve(){
	int n; cin >> n;

	vector<int> divv;
	for(int i = 1; i*i <= n; i++) if(n%i == 0){
		divv.emplace_back(i);
		if(n/i != i) divv.emplace_back(n/i);
	}

	sort(divv.begin(), divv.end());

	int memodp[15][2400], memocnt[15][2400];
	memset(memodp, 0, sizeof memodp);
	memset(memocnt, 0, sizeof memocnt);

	int d = divv.size();
	memocnt[0][0] = 1;
	for(int i = 0; i < d; i++) for(int j = 14; j > 0; j--) for(int p_idx = 0; p_idx < d; p_idx++){
		int p = divv[p_idx];

		// choose i
		if(p%divv[i] == 0){
			int lb = lower_bound(divv.begin(), divv.end(), p/divv[i])-divv.begin();

			memocnt[j][p_idx] += memocnt[j-1][lb];
			memocnt[j][p_idx] %= MOD;

			memodp[j][p_idx] += (divv[i] % MOD * memocnt[j-1][lb] % MOD) + memodp[j-1][lb];
			memodp[j][p_idx] %= MOD;
		}
	}

	int ans = 0, fact = 1;
	for(int i = 1; i <= 14; i++) fact = fact*i%MOD, ans += memodp[i][d-1]*fact%MOD, ans %= MOD;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
