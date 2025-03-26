#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

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
	string s; cin >> s;
	vector<int> dp(n+1); int inv2 = fexp(2, MOD-2);
	for(int i = n-1; i >= 1; i--){
		dp[i] = (dp[i+1]+(s[i]=='1'))*inv2%MOD;
	}

	cout << (dp[1]+n-1)%MOD << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
