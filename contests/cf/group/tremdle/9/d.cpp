#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10, MOD = 998244353;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

void add(int& a, int b){
	a += b;
	a %= MOD;
}

void sub(int& a, int b){
	a -= b;
	a %= MOD;
	a += MOD;
	a %= MOD;
}

vector<int> fact(MAX);

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	int one = 0;
	for(auto x: s) one += (x == '1');

	int ans = fexp(2, one+2*(n-1));

	sub(ans, fexp(2, fact[one-1]));

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

	fact[0] = 1;
	for(int i = 1; i < MAX; i++) fact[i] = fact[i-1]*i%MOD;

    while(ttt--) solve();

    exit(0);
}
