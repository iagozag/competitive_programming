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
	cout << "NO" << endl;
}

void yes(){
	cout << "YES" << endl;
}

void solve(){
	int n, cnt = 0; cin >> n;
	vector<int> d1, d2;

	vector<vector<int>> v(n, vector<int>(n));
	for(int i = 0 ; i < n; i++) for(int j = 0; j < n; j++){
		char c; cin >> c; v[i][j] = (c == '#');
		if(v[i][j]) cnt++, d1.emplace_back(i-j), d2.emplace_back(i+j);
	}

	// line
	for(int i = 0; i < n; i++) for(int j = 0; j < n-2; j++) if(v[i][j] and v[i][j+1] and v[i][j+2])
		return no();

	// column
	for(int i = 0; i < n-2; i++) for(int j = 0; j < n; j++) if(v[i][j] and v[i+1][j] and v[i+2][j])
		return no();

	// square and more
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-1; j++) if(v[i][j] and v[i][j+1] and v[i+1][j] and v[i+1][j+1])
			return (cnt == 4 ? yes() : no());
	}

	if(!d1.size()) return yes();

	sort(d1.begin(), d1.end());
	sort(d2.begin(), d2.end());

	if(d1.back()-d1[0] <= 1 or d2.back()-d2[0] <= 1) return yes();
	return no();
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
