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
	int n; cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	int ans = 0;

	map<int, int> row, col;
	map<pair<int, int>, int> dl, dr;
	for(int i = 0; i < n; i++){
		int le = y[i]-x[i], ri = y[i]+x[i];
		ans += row[x[i]]+col[y[i]]+dl[{0, le}]+dr[{0, ri}];
		row[x[i]]++, col[y[i]]++, dl[{0, le}]++, dr[{0, ri}]++;
	}

	cout << (ans<<1) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
