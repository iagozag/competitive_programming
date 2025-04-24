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
	int n, x, y; cin >> n >> x >> y;
	string ans = "";
	string s; cin >> s; int px = 0, py = 0;
	set<pair<int, int>> st; st.insert({px, py});
	for(auto c: s){
		if(c == 'N') x++, px++;
		if(c == 'S') x--, px--;
		if(c == 'W') y++, py++;
		if(c == 'E') y--, py--;

		st.insert({px, py});

		ans += (st.count({x, y}) ? '1' : '0');
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
