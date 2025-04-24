#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, k; cin >> n >> k;

	int tot = 0;
	if(n > 60) tot = LINF;
	else tot = (1LL<<(n-1));

	if(k > tot){ cout << -1 << endl; return; }

	vector<int> ans(n); int num = 1, l = 0, r = n-1;
	for(int i = 0; i < n; i++){
		if((n-i-1) < 60 and k > (1LL<<(max(0LL, n-i-2)))){
			ans[r--] = num++;
			k -= (1LL<<(max(0LL, n-i-2)));
		} else{
			ans[l++] = num++;
		}
	}

	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
