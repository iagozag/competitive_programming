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
	sort(v.begin(), v.end());
 
	int ans = 0;
	int l = 0, r = n-1; vector<int> vis(n);
	while(l < r){
		while(r > l and v[l]+v[r] > k) r--;
		if(l < r and v[l]+v[r] <= k) vis[l] = vis[r] = 1, l++, r--, ans++;
	}
 
	for(int i = 0; i < n; i++) if(!vis[i]) ans++;
	cout << ans << endl;
}
 
int32_t main(){ _
    int ttt = 1; // cin >> ttt;
 
    while(ttt--) solve();
 
    exit(0);
}
