#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const long double INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;
const long double EPS = 1e-10;

int n; vector<long double> v(15);
vector<vector<long double>> mice(15);

long double dist(tuple<long double, long double, long double, long double> p){
	auto [a, b, c, d] = p;
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		long double a, b, c; cin >> a >> b >> c; mice[i] = {a, b, c};
	}

	long double vel; cin >> vel;

	vector<vector<long double>> dp;
	long double l = 0, r = 1e9, ans = r;
	while(r-l > EPS){
		long double mid = (r+l)/2.0;

		v[0] = mid;
		for(int i = 1; i < n; i++) v[i] = v[i-1]*vel;

		dp = vector<vector<long double>>(1<<n, vector<long double>(n, INF));
		for(int i = 0; i < n; i++){
			long double best = dist({0, 0, mice[i][0], mice[i][1]})/v[0];
			if(best < mice[i][2]) dp[1<<i][i] = best;
		}

		for(int i = 1; i < (1<<n); i++) for(int j = 0; j < n; j++) if(!(i&(1<<j))){
			for(int k = 0; k < n; k++) if(i&(1<<k)){
				long double best = dp[i][k]+(dist({mice[j][0], mice[j][1], mice[k][0], mice[k][1]})/v[__builtin_popcount(i)]);
				if(best < mice[j][2]) dp[i|(1<<j)][j] = min(dp[i|(1<<j)][j], best);
			}
		}

		long double t = INF;
		for(int i = 0; i < n; i++) t = min(t, dp[(1<<n)-1][i]);
		if(t < INF) ans = mid, r = mid;
		else l = mid;
	}

	cout << fixed << setprecision(12) << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
