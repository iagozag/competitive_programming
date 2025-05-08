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
	vector<int> a(n), b(n);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	vector<int> pref(n);
	for(int i = 0; i < n; i++) pref[i] = (i ? pref[i-1] : 0)+a[i];

	auto get_sum = [&](int a, int b) -> int{
		return pref[b]-(a ? pref[a-1] : 0);
	};

	vector<int> vis(n);
	int j = 0, ans = 0, tot = 0;
	while(j >= 0){
		while(j >= 0 and vis[j]) j--;
		if(j < 0) break;

		if(b[j] > j and ){
			
			ans = max(ans, pref[j]-took);
			took += a[j];
		}

		vis[j] = 1;
	}

	ans = max(ans, pref[n-1]-took);

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
