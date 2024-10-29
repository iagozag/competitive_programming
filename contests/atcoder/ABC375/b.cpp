#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

long double dist(long double a, long double b, long double c, long double d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

void solve(){
	int n; cin >> n;
	long double px = 0, py = 0; long double ans = 0;
	for(int i = 0; i < n; i++){
		long double x, y; cin >> x >> y;
		ans += dist(px, py, x, y);
		px = x, py = y;
	}
	ans += dist(px, py, 0, 0);
	cout << fixed << setprecision(12) << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
