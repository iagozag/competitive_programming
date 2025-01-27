#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

long double d(long double a,long double b, long double c,long double d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

void solve(){
	int n; cin >> n;
	vector<pair<long double, long double>> v(n); for(auto& x: v) cin >> x.first >> x.second;
	for(int i = 0; i < n; i++){
		int ans = -1; long double dist = 0;
		for(int j = 0; j < n; j++) if(i != j){
			long double dd = d(v[i].first, v[i].second, v[j].first, v[j].second);
			if(dist < dd) dist = dd, ans = j;
		}
		cout << ans+1 << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
