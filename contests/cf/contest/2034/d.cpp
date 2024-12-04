#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> v(n); vector<set<int, greater<int>>> pos(3);
	for(int i = 0; i < n; i++){
		int a; cin >> a; v[i] = a;
		pos[a].insert(i);
	}

	vector<pair<int, int>> ans;
	vector<int> sorted = v; sort(sorted.begin(), sorted.end());
	for(int i = 0; i < n; i++){
		pos[v[i]].erase(i);
		while(v[i] > sorted[i]){
			int idx = *pos[v[i]-1].begin();
			ans.emplace_back(i+1, idx+1);
			pos[v[i]-1].erase(idx);
			pos[v[i]].insert(idx);
			v[i]--, v[idx]++;
		}
	}

	cout << ans.size() << endl;
	for(auto x: ans) cout << x.first << " " << x.second << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
