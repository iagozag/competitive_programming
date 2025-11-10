#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, k, x;
vector<int> v;

set<int> good(int m){
	set<int> ans;
	for(int i = 0; i <= v[0]-m and (int)ans.size() < k; i++) ans.insert(i);
	for(int i = v.back()+m; i <= x and (int)ans.size() < k; i++) ans.insert(i);

	for(int i = 1; i < n; i++){
		for(int j = v[i-1]+m; j <= v[i]-m and (int)ans.size() < k; j++) 
			ans.insert(j);
	}

	return (ans.size() == k ? ans : set<int>());
}

void solve(){
	cin >> n >> k >> x;
	v = vector<int>(n); for(auto& y: v) cin >> y;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int l = 0, r = x; set<int> ans;
	while(l <= r){
		int mid = l+(r-l)/2;
		set<int> tmp = good(mid);
		if(tmp.size() != 0) ans = tmp, l = mid+1;
		else r = mid-1;
	}

	for(auto y: ans) cout << y << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
