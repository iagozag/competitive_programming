#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void yes(int i, int j, int k){ cout << i+1 << ' ' << j+1 << ' ' << k+1 << endl; return; }

vector<pair<pair<int, int>, int>> v;

bool check(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	pair<int, int> v1 = {b.first-a.first, b.second-a.second}, v2 = {c.first-b.first, c.second-b.second};
	
	return v1.first*v2.second != v2.first*v1.second;
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){ int a, b; cin >> a >> b; v.emplace_back(make_pair(a, b), i); }
	sort(v.begin(), v.end());

	for(int i = 0; i < n-2; i++){
		if(check(v[i].first, v[i+1].first, v[i+2].first))
			return yes(v[i].second, v[i+1].second, v[i+2].second);
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
