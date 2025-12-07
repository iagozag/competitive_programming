#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1<<20, MOD = 1e9+7;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	vector<vector<int>> f(MAX, vector<int>(21));
	for(int i = 0; i < n; i++){ int x; cin >> x; f[x][0]++; }

	for(int i = (1<<20)-1; i >= 0; i--) for(int j = 1; j <= 20; j++){
		f[i][j] = f[i][j-1];
		if(!((i>>(j-1))&1))
			f[i][j] += f[i|(1<<(j-1))][j-1];
	}

	int ans = 0;
	for(int i = 0; i < (1<<20); i++){
		ans += ((__builtin_popcount(i)&1) ? -1 : 1) * ((fexp(2, f[i][20]))-1);
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

