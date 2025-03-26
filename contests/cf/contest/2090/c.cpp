#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10, MOD = 1e9+7;

vector<pair<int, int>> squares;
vector<int> vis(MAX);

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;

	vector<pair<int, int>> ans(n); int l = 0, r = 0;
	vector<int> cl;
	for(int i = 0; i < n; i++){
		if(!v[i]) vis[r] = 1, cl.emplace_back(r), ans[i] = squares[r++];
		else vis[l] = 1, cl.emplace_back(l), ans[i] = squares[l++];

		while(vis[l]) l++;
		while(l > r or vis[r] or ((squares[r].first-1)%3 != 0) or ((squares[r].second-1)%3 != 0)) r++;
	}

	for(auto x: cl) vis[x] = 0;
	
	for(int i = 0; i < n; i++) cout << ans[i].first << ' ' << ans[i].second << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	vector<pair<int, pair<int, int>>> sq;
	for(int y = 1; y < 1500; y += 3){
		int tmp = y;
		for(int x = 1; x <= y; x += 3){
			sq.push_back({x+tmp, {x, tmp}});
			sq.push_back({x+tmp+1, {x+1, tmp}});
			sq.push_back({x+tmp+1, {x, tmp+1}});
			sq.push_back({x+tmp+4, {x+1, tmp+1}});

			tmp -= 3;
		}
	}

	sort(sq.begin(), sq.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
		if(a.first != b.first) return a.first < b.first;
		if(a.second.first != b.second.first) return a.second.first < b.second.first;
		return a.second.second < b.second.second;
	});

	for(auto x: sq) squares.push_back(x.second);

    while(ttt--) solve();

    exit(0);
}
