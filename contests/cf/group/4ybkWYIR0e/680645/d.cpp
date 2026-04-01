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
	int n, x = 0, y = 0; cin >> n;
	set<pair<int, int>> st;
	for(int i = 0; i < n; i++){ int a, b; cin >> a >> b; st.insert({a, b}); }

	auto val = [&](int i, int j) -> bool{
		return i >= 0 and i < 100 and j >= 0 and j < 100  and !st.count({i, j});
	};

	string s; cin >> s; int m = s.size();
	for(int i = 0; i < m; i++){
		if(s[i] == 'F' and val(x, y+1)) y++;
		else if(s[i] == 'T' and val(x, y-1)) y--;
		else if(s[i] == 'D' and val(x+1, y)) x++;
		else if(s[i] == 'E' and val(x-1, y)) x--;
	}

	cout << x << ' ' << y << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
