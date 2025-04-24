#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void yes(){
	cout << "YES" << endl;
}

void no(){
	cout << "NO" << endl;
}

void solve(){
	int n, k; cin >> n >> k;
	vector<int> v(n); for(auto& x: v) cin >> x;
	vector<int> pref(n); pref[0] = (v[0] <= k);
	for(int i = 1; i < n; i++) pref[i] = pref[i-1]+(v[i] <= k);

	int l = 0, r = n-1;
	while(l < n-2 and pref[l] < (l+2)/2) l++;

	while(r >= 2 and pref[n-1]-pref[r-1] < (n-r+1)/2) r--;

	if(r > l+1) return yes();

	if(l%2 == 0 and v[l+1] > k) l++;
	if((n-r)%2 and v[r-1] > k) r--;

	for(int i = l+1; i < n-1; i++) if(pref[i]-pref[l] >= (i-l+1)/2) return yes();
	for(int i = r-1; i >= 1; i--) if(pref[r-1]-pref[i-1] >= (r-i+1)/2) return yes();
	return no();
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
