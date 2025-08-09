#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;
const long double EPS = 1e-9;
const long double G = 6.67430*1e-11;

long double f(long double m1, long double m2, long double d){
	return (G*m1*m2)/(d*d);
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int> a(n), b(n);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	cout << n-1 << endl;
	for(int i = 0; i < n-1; i++){
		long double l = a[i], r = a[i+1];
		while(r-l > EPS){
			long double mid = (l+r)/2.0;

			long double fl = 0, fr = 0;
			for(int j = 0; j <= i; j++) fl += f(b[j], m, fabs(mid-(long double)a[j]));
			for(int j = i+1; j < n; j++) fr += f(b[j], m, fabs(mid-(long double)a[j]));
			if(fl > fr) l = mid;
			else r = mid;
		}

		cout << fixed << setprecision(9) << l << ' ';
	}

	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
