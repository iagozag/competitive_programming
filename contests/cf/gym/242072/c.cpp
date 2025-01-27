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
	int mat[n][n]; memset(mat, 0, sizeof mat);
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; mat[a][b] = mat[b][a] = 1; }

	int ans = INF;
	for(int i = 0; i < (1<<n); i++){
		vector<int> a, b;
		for(int j = 0; j < n; j++){
			if(i&(1<<j)) a.emplace_back(j);
			else b.emplace_back(j);
		}

		int sum = 0;
		for(int j = 0; j < (int)a.size(); j++) for(int k = j+1; k < (int)a.size(); k++) 
			if(mat[a[j]][a[k]]) sum++;
		for(int j = 0; j < (int)b.size(); j++) for(int k = j+1; k < (int)b.size(); k++) 
			if(mat[b[j]][b[k]]) sum++;

		ans = min(ans, sum);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
