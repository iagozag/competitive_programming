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
	int n; cin >> n; int cnt = 0, cnt2 = 0;
	vector<int> v(n); for(auto& x: v) cin >> x, cnt2 += (x == -1), cnt += (x == 1);
	int ans = 0;
	while(cnt < cnt2) ans++, cnt++, cnt2--;	

	if((cnt2&1)) ans++;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
