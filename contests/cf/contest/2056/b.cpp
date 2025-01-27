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
	vector<vector<int>> v(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < n; j++) v[i][j] = (s[j] == '1');
	}

	int ans[n]; for(int i = 0; i < n; i++) ans[i] = i;

	sort(ans, ans+n, [&](int i, int j){
		if(v[i][j]) return i < j;
		return i > j;
	});

	for(int i = 0; i < n; i++) cout << ans[i]+1 << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
