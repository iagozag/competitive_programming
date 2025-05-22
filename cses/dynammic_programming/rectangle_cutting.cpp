#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<vector<int>> memo;

int dp(int a, int b){
	if(a == b) return memo[a][b] = 0;

	if(memo[a][b] != LINF) return memo[a][b];

	for(int i = 1; i < a; i++) memo[a][b] = min(memo[a][b], dp(i, b)+dp(a-i, b)+1);
	for(int i = 1; i < b; i++) memo[a][b] = min(memo[a][b], dp(a, i)+dp(a, b-i)+1);

	return memo[a][b];
}

void solve(){
	int a, b; cin >> a >> b;
	memo = vector<vector<int>>(a+1, vector<int>(b+1, LINF));

	cout << dp(a, b) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
