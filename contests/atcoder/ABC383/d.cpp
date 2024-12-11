#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e6+10, MOD = 1e9+7;

vector<int> lp(MAX+1);
vector<int> pr;

void sieve(){
	for (int i = 2; i <= MAX; ++i) {
		if (lp[i] == 0)
			lp[i] = i, pr.push_back(i);

		for (int j = 0; i * pr[j] <= MAX; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) break;
		}
	}
}

void solve(){
	int n; cin >> n;

	sieve();
	
	int m = pr.size(), ans = 0;
	for(int i = 0; i < m; i++){
		int l = i, r = m-1, tot = i;
		while(l <= r){
			int mid = l+(r-l)/2;
			if(pr[mid]*pr[mid] <= n and pr[i]*pr[i]*pr[mid] <= n and pr[i]*pr[i]*pr[mid]*pr[mid] <= n) tot = mid, l = mid+1;
			else r = mid-1;
		}
		ans += tot-i;
		int sum = 1;
		for(int j = 0; j < 8 and sum <= n; j++) sum *= pr[i];
		if(sum <= n) ans++;
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
