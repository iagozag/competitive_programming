#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	ll n, m; cin >> n >> m; vector<pair<ll, ll>> p(m);
	set<pair<ll, ll>> cant;
	for(int i = 0; i < m; i++){
		cin >> p[i].first >> p[i].second; cant.insert({p[i].first, p[i].second});
	}

	vector<pair<ll, ll>> moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, -1}, {2, 1}, {-2, 1}, {-2, -1}};

	for(auto [x, y]: p){
		for(auto [a, b]: moves) {
			ll nx = x+a, ny = y+b;
			if(nx < 1 or nx > n or ny < 1 or ny > n) continue;
			cant.insert({nx, ny});
		}
	}
	cout << n*n-cant.size() << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
