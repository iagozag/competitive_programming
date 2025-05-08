#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int> v(n); set<int> st;
	for(int i = 0; i < n; i++) cin >> v[i], st.insert(v[i]);

	map<int, int> mp, mpr; int k = 0;
	for(auto x: st) mp[x] = k, mpr[k] = x, k++;
	
	vector<int> qnt(k);
	for(auto x: v) qnt[mp[x]]++;

	vector<int> pref(k+1, 1);
	for(int i = 1; i < k+1; i++) pref[i] = pref[i-1]*qnt[i-1]%MOD;

	int ans = 0;
	for(int i = 0; i < k; i++){
		int l = i, r = k-1, idx = l;
		while(l <= r){
			int mid = l+(r-l)/2;
			if(mpr[mid]-mpr[i] < m) idx = mid, l = mid+1;
			else r = mid-1;
		}

		if(idx-i+1 < m) continue;

		ans += (pref[idx+1]*fexp(pref[i], MOD-2))%MOD, ans %= MOD;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
