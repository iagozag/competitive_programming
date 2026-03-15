#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

void dfs(int v, vector<vector<int>>& g, vector<int>& vis){
	vis[v] = 1;
	for(int j = 0; j < (int)g[v].size(); j++) if(!vis[g[v][j]]) dfs(g[v][j], g, vis);
}

int32_t main(){
	int ttt; cin >> ttt;
	while(ttt--){
		char c; cin >> c;
		int n = (int)(c-'A')+1;
		cin.ignore();

		vector<vector<int>> g(n);
		vector<int> vis(n);

		string edge;
		while(getline(cin, edge) && edge != ""){
			int a = (int)(edge[0]-'A'), b = (int)(edge[1]-'A');
			g[a].emplace_back(b), g[b].emplace_back(a);
		}

		int ans = 0;
		for(int i = 0; i < n; i++) if(!vis[i]) ans++, dfs(i, g, vis);

		cout << ans << endl;

		if(ttt) cout << endl;
	}

	exit(0);
}
