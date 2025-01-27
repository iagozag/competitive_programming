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
	int n, l, r; cin >> n >> l >> r; --l, --r;
	vector<int> v(n); for(auto& x: v) cin >> x;
	vector<int> acc, acc2;
	for(int i = l; i < n; i++) acc.emplace_back(v[i]);
	for(int i = 0; i <= r; i++) acc2.emplace_back(v[i]);
	sort(acc.begin(), acc.end()), sort(acc2.begin(), acc2.end());
	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < r-l+1; i++) ans1 += acc[i], ans2 += acc2[i];
	cout << min(ans1, ans2) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
