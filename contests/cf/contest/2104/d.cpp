#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;
const int N = 10000000;

vector<int> lp(N+1);
vector<int> pr;

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;
	sort(v.begin(), v.end());

	int l = 0, r = n-1, ans = r;
	while(l <= r){
		int m = l+(r-l)/2;

		int need = 0;
		for(int i = m, j = 0; i < n; i++, j++) need += v[i]-pr[j];

		if(need >= 0) ans = m, r = m-1;
		else l = m+1;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	for (int i=2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) {
				break;
			}
		}
	}

    while(ttt--) solve();

    exit(0);
}
