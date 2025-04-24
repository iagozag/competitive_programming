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
	int n, ans = 0; cin >> n;
	vector<vector<int>> row(MAX), col(MAX);
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		col[a].emplace_back(b), row[b].emplace_back(a);
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < MAX; i++) sort(col[i].begin(), col[i].end()), sort(row[i].begin(), row[i].end());

	rect r; r.reset();
	for(int i = 0; i < 1e5+10; i++) if(col[i].size()){
		if(i <= r.maxx){
			ans -= col[i].size();
			r.miny = min(r.miny, col[i][0]);
			r.maxy = max(r.maxy, col[i].back());
			continue;
		}
		else{
			ans += r.get_area();
			r.reset();
		}

		int sum = 0, minx = LINF, maxx = -1;
		for(auto y: col[i]) if(row[y].size()){
			sum += row[y].size()-1;
			minx = min(minx, row[y][0]), maxx = max(maxx, row[y].back());
		}

		if(sum == 0) continue;

		r.minx = minx, r.maxx = maxx, r.miny = min(r.miny, col[i][0]), r.maxy = max(r.maxy, col[i].back());
	}

	ans += r.get_area();

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
