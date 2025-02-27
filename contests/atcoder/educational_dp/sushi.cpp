#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 301, MOD = 1e9+7;

int N; int v[3] = {0};
long double memo[MAX][MAX][MAX];

long double dp(long double x, long double y, long double z){
	long double n = N; int X = x, Y = y, Z = z;

	if(X < 0 or Y < 0 or Z < 0) return 0;
	if(memo[X][Y][Z] != -1) return memo[X][Y][Z];

	memo[X][Y][Z] = 0;
	return memo[X][Y][Z] = (1.0/(x+y+z))*(n+x*dp(x-1,y,z)+y*dp(x+1,y-1,z)+z*dp(x,y+1,z-1));
}

void solve(){
	for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++) for(int k = 0; k < MAX; k++) memo[i][j][k] = -1;

	cin >> N;
	for(int i = 0; i < N; i++){ int x; cin >> x; v[x-1]++; }
	memo[0][0][0] = 0;

	cout << fixed << setprecision(12) << dp(v[0], v[1], v[2]) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
