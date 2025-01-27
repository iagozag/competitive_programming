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
	string s; cin >> s;
	int v[n][m];
	int row[n], col[m]; memset(row, 0, sizeof row), memset(col, 0, sizeof col);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j], row[i] += v[i][j], col[j] += v[i][j];

	int i = 0, j = 0, sum = 0;
	if(s[0] == 'R'){
		for(int k = 0; k < n; k++) sum += v[k][0];
		v[0][0] = -sum;
		j++;
	} else{
		for(int k = 0; k < m; k++) sum += v[0][k];
		v[0][0] = -sum;
		i++;
	}

	row[0] += v[0][0], col[0] += v[0][0];

	for(int k = 1; k < (int)s.size(); k++){
		if(s[k] == 'D') v[i][j] = -row[i], row[i] += v[i][j], col[j] += v[i][j], i++;
		else v[i][j] = -col[j], row[i] += v[i][j], col[j] += v[i][j], j++;
	}

	v[n-1][m-1] = -row[i];

	for(int l = 0; l < n; l++) for(int k = 0; k < m; k++) cout << v[l][k] << " \n"[k==m-1];
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
