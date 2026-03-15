#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

struct cmp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		int sza = a.second-a.first, szb = b.second-b.first;
        if(sza != szb) return sza > szb;
		return a.first < b.first;
    }
};

void solve(){
	int n; cin >> n;
	priority_queue<tuple<int, int, int>> q; q.push({n, 0, n-1}); int k = 1;
	vector<int> ans(n);
	while(!q.empty()){
		auto [sz, l, r] = q.top(); q.pop(); l *= -1;
		int mid = (sz&1 ? (l+r)/2 : (l+r-1)/2);
		ans[mid] = k++;
		if(l <= mid-1) q.emplace(mid-l, -l, mid-1);
		if(mid+1 <= r) q.emplace(r-mid, -(mid+1), r);
	}

	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


