#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e3, MOD = 1e9+7;

vector<int> lp(MAX+1);
vector<int> pr;

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	for(auto p: pr)
		for(int i = 0; i < n; i++) if(__gcd(p, v[i]) == 1){ cout << p << endl; return; }
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	for (int i=2; i <= MAX; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= MAX; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) {
				break;
			}
		}
	}

    while(ttt--) solve();

    exit(0);
}
