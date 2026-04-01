#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

bool good(vector<int> v, int x){
	for(int i = 0; i < (int)v.size(); i++) v[i] -= x;
	for(int i = 0; i < (int)v.size(); i++) if(v[i] > 0) x -= v[i];
	return x >= 0;
}

void solve(){
	int n; cin >> n;
	vector<int> child(n); for(int i = 0; i < n-1; i++){ int x; cin >> x; --x; child[x]++; }
	vector<int> v = {1};
	for(auto x: child) if(x) v.emplace_back(x);
	sort(v.rbegin(), v.rend());

	n = v.size();
	int ans = n;
	for(int i = 0; i < n; i++) v[i] -= n-i;
	sort(v.rbegin(), v.rend());

	int l = 0, r = 1e5+10, need = r;
	while(l <= r){
		int mid = l+(r-l)/2;
		
		if(good(v, mid)) need = mid, r = mid-1;
		else l = mid+1;
	}

	cout << ans+need << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
