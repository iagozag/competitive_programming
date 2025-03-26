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
	int flip[n][n][3]; memset(flip, 0, sizeof flip);
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < n; j++) v[i][j] = s[j] == '1';
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int tot = flip[i][j][0]+flip[i][j][1]+flip[i][j][2];
			if(tot&1) v[i][j] = !v[i][j];

			if(v[i][j]){
				ans++;
				flip[i][j][1]++;
			}

			if(i < n-1){
				if(j) flip[i+1][j-1][0] += flip[i][j][0]+flip[i][j][1];
				flip[i+1][j][1] += flip[i][j][1];
				if(j < n-1) flip[i+1][j+1][2] += flip[i][j][2]+flip[i][j][1];
			}
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
