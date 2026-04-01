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
		b >>= 1, a = a*a%MOD;
	}	
	return ans;
}

vector<vector<vector<int>>> memo;
vector<int> inv;
string s;
int n;

int dp(int i, int j, int k){
	if(i == 0 and j == 0) return k == n;

	int& p = memo[i][j][k];
	if(p != -1) return p;
	p = 0;
	
	// bola A
	if(i) p += i*inv[i+j]%MOD*((s[k] == 'A' and k+1 <= n ? dp(i-1, j, k+1) : 0)+dp(i-1, j, k))%MOD;
	// bola V
	if(j) p += j*inv[i+j]%MOD*((s[k] == 'V' and k+1 <= n ? dp(i, j-1, k+1) : 0)+dp(i, j-1, k))%MOD;

	p %= MOD;
	return p;
}

void solve(){
	cin >> s; n = s.size();
	int a, b; cin >> a >> b;
	memo = vector<vector<vector<int>>>(a+1, vector<vector<int>>(b+1, vector<int>(n+1, -1)));

	cout << dp(a, b, 0) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

	inv = vector<int>(1010);
	for(int i = 0; i < 1010; i++) inv[i] = fexp(i, MOD-2);

    while(ttt--) solve();

    exit(0);
}
