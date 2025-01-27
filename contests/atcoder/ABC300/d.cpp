#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+10, MOD = 1e9+7;

vector<int> lp(MAX+1);
vector<int> pr;

void sieve(){
	for(int i = 2; i <= MAX; i++){
		if(!lp[i]) lp[i] = i, pr.emplace_back(i);
		for(int j = 0; i*pr[j] <= MAX; j++){
			lp[i*pr[j]] = pr[j];
			if(pr[j] == lp[i]) break;
		}
	}
}

void solve(){
	int n; cin >> n; sieve();

	int m = pr.size(), ans = 0;
	for(int i = 0; i < m; i++){
		if(pr[i]*pr[i] > n) break;
		for(int j = i+1; j < m; j++){
			if(pr[i]*pr[i]*pr[j] > n) break;

			int l = j+1, r = m-1, idx = j;
			while(l <= r){
				int mid = l+(r-l)/2;
				if(pr[i]*pr[i]*pr[j]*pr[mid] <= n and pr[i]*pr[i]*pr[j]*pr[mid]*pr[mid] <= n) l = mid+1, idx = mid;
				else r = mid-1;
			}

			if(idx > j) ans += idx-j;
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
