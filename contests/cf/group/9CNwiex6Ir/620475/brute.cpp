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
	int n, m; cin >> n >> m;
	vector<string> v(n); for(auto& s: v) cin >> s;

	int ans = 0;
	for(int j = 0; j < n; j++){
		int can = 1;
		for(int i = 0; i < m/2; i++) if(v[j][i] != v[j][m-i-1]) can = 0;
		ans += can;
	}

	for(int j = 0; j < n; j++){
		for(int k = j+1; k < n; k++){
			string c = "";
			for(int i = 0; i < m; i++){
				int x = v[j][i]-'a', y = v[k][i]-'a';
				c += ((x+y)%26)+'a';
			}

			int can = 1;
			for(int i = 0; i < m/2; i++) if(c[i] != c[m-i-1]) can = 0;
			ans += can*2;
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
