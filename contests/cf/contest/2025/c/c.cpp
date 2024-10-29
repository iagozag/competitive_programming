#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, k; cin >> n >> k;
	vector<int> v(n); for(auto& x: v) cin >> x;
	sort(v.begin(), v.end());

	int l = 0, r = 1, ans = 1;
	while(r < n){
		while(r < n and (r == l or v[r]-v[r-1] <= 1) and v[r]-v[l] < k) r++;
		ans = max(ans, r-l), l++;
	}

	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
