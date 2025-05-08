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
	int n; cin >> n;
	int m = 1, j = 3; vector<int> ans(n, -1);
	while(m < n) m += j, j += 2;

	for(int i = n-1; i > 0; i--) if(ans[i] == -1){
		while(m-i >= n or m-i > i or ans[m-i] != -1) j -= 2, m -= j;
		ans[i] = m-i, ans[m-i] = i;
	}
	if(ans[0] == -1) ans[0] = 0;

	for(int i = 0; i < n; i++) if(ans[i] == -1){ cout << -1 << endl; return; }

	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
