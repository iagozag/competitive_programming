#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){
	cout << "No" << endl;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>> v;
	for(int i = 0; i < m; i++){ int a, b; char c; cin >> a >> b >> c; v.emplace_back(a, b, c); }
	sort(v.begin(), v.end());
	int mi = INF;
	for(auto [a, b, c]: v){
		if(c == 'W') mi = min(mi, b);
		else{
			if(b >= mi) return no();
		}
	}

	cout <<"Yes" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
