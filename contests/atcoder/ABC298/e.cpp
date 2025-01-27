#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

int memo[110][100][2];
int N, A, B, P, Q, PP, QQ;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

int dp(int a, int b, int turn){
	if(a < A or b < B) return 0;
	if(memo[a][b][turn] != -1) return memo[a][b][turn];

	int sum = 0;
	if(turn){
		for(int i = (a > N ? N-1 : a-1); i >= a-P; i--) sum += dp(i, b, !turn), sum %= MOD;
		sum *= PP, sum %= MOD;
	} else{
		for(int i = (b > N ? N-1 : l-1); i >= b-Q; i--) sum += dp(a, i, !turn), sum %= MOD;
		sum *= QQ, sum %= MOD;
	}

	return memo[a][b][turn] = sum;
}

void solve(){
	cin >> N >> A >> B >> P >> Q;
	PP = fexp(P, MOD-2), QQ = fexp(Q, MOD-2);

	for(int i = 0; i < 110; i++) for(int j = 0; j < 100; j++) for(int k = 0; k < 2; k++) memo[i][j][k] = -1;	
	memo[A][B][0] = 1;
	int sum = 0;
	for(int j = N; j < N+P; j++) for(int i = B; i < N; i++)
		sum += dp(j, i, 1), sum %= MOD;

	cout << sum << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
