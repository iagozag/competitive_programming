#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<vector<int>> vis(10, vector<int>(10));
vector<string> v(10);
int n, m;
void dfs(int i, int j){
	vis[i][j] = 1;
	if(i+1 < n and v[i+1][j] == '#') dfs(i+1, j);
	else if(j+1 < m and v[i][j+1] == '#') dfs(i, j+1);
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> v[i];

	dfs(0, 0);

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(v[i][j] == '#' and !vis[i][j]){ cout << "Impossivel" << endl; return; }

	if(vis[n-1][m-1]) cout << "Possivel" << endl;
	else cout << "Impossivel" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

