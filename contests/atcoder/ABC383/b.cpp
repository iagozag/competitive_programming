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
	int n, m, d; cin >> n >> m >> d;
	vector<string> v(n); for(auto& x: v) cin >> x;
	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) 
	for(int k = 0; k < n; k++) for(int l = 0; l < m; l++) if(v[i][j] == '.' and v[k][l] == '.'){
		int sum = 0;
		for(int a = 0; a < n; a++) for(int b = 0; b < m; b++){
			if(v[a][b] == '.' and (abs(a-i)+abs(b-j) <= d or abs(a-k)+abs(b-l) <= d)) sum++;
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
