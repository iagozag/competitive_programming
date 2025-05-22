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
	vector<int> v(n); for(auto& x: v) cin >> x;

	int l = 0, r = 0, ans = 0;
	map<int, int> mp;
	while(l < n){
		while(r < n and ((int)mp.size() < k or ((int)mp.size() == k and mp.count(v[r])))){
			ans += r-l+1;
			mp[v[r]]++;
			r++;
		}
		mp[v[l]]--;
		if(mp[v[l]] == 0) mp.erase(v[l]);
		l++;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
