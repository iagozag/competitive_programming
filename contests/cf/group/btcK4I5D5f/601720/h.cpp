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
	vector<pair<int, int>> v(n); for(int i = 0; i < n; i++){ cin >> v[i].first, v[i].second = i; }
	sort(v.begin(), v.end());

	vector<int> ans;
	int mi = n-1;
	for(int i = 0; i < n; i++){
		int l = i, r = n-1, m = (l+r)/2;
		if(v[m].first == k){ mi = i; break; }
	}

	for(int i = 0; i < mi; i++) ans.emplace_back(v[i].second);

	reverse(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		int l = i, r = n-1, m = (l+r+1)/2;
		if(v[m].first == k){ mi = i; break; }
	}

	if(mi < (int)ans.size() or (int)ans.size() == 0){
		ans.clear();
		for(int i = 0; i < mi; i++) ans.emplace_back(v[i].second);
	}

	cout << ans.size() << endl;
	for(auto x: ans) cout << x+1 << ' ';
	if(ans.size()) cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
