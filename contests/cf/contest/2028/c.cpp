#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

ll n, m, k;

void dp(vector<ll>& v, vector<ll>& memo){
	memo[0] = (v[0] >= k);
	for(int i = 1; i < (int)v.size(); i++) if(v[i] >= k){
		int ub = upper_bound(v.begin(), v.end(), v[i]-k)-v.begin(); ub--;
		memo[i] = max(memo[i-1], (ub >= 0 ?  memo[ub] : 0)+1);
	}
}

void solve(){
	cin >> n >> m >> k;
	vector<ll> v(n); for(auto& x: v) cin >> x;
	vector<ll> pref(n); for(int i = 0; i < n; i++) pref[i] = (i ? pref[i-1] : 0)+v[i];

	vector<ll> subl(n), subr(n);
	dp(pref, subl);
	reverse(v.begin(), v.end());
	for(int i = 0; i < n; i++) pref[i] = (i ? pref[i-1] : 0)+v[i];
	dp(pref, subr);
	reverse(v.begin(), v.end()), reverse(subr.begin(), subr.end());

	ll le = -1, ri = 1e18, ans = -1;
	while(le <= ri){
		ll mid = le+(ri-le)/2;

		int l = 0, r = 0; ll sum = 0; bool can = false;
		while(l < n){
			while(r < n and (r < l or sum < mid)) sum += v[r++];
			if(sum >= mid and (l ? subl[l-1] : 0)+(r < n ? subr[r] : 0) >= m){
				can = true;
				break;
			}
			sum -= v[l++];
		}

		if(can) ans = mid, le = mid+1;
		else ri = mid-1;
	}

	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
