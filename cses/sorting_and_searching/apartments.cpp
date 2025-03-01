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
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;
	sort(a.begin(), a.end()), sort(b.begin(), b.end());

	int i = 0, j = 0, ans = 0;
	while(i < n and j < m){
		if(abs(b[j]-a[i]) <= k) ans++, i++, j++;
		else if(b[j] < a[i]) j++;
		else i++;
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
