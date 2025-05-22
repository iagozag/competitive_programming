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
	int n, x; cin >> n >> x;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].first, v[i].second = i;
	sort(v.begin(), v.end());

	int l = 0, r = n-1;
	while(l < r){
		int sum = v[l].first+v[r].first;
		if(sum == x){ cout << v[l].second+1 << ' ' << v[r].second+1 << endl; return; }
		if(sum < x) l++;
		else r--;
	}

	cout << "IMPOSSIBLE" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
