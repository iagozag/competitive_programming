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
	vector<pair<int, int>> edges;
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		edges.emplace_back(a, b);
	}

	vector<int> vis(3*n+1); vector<int> match;
	for(int i = 0; i < edges.size(); i++){
		auto [a, b] = edges[i];
		if(!vis[a] and !vis[b]) match.emplace_back(i+1), vis[a] = vis[b] = 1;
	}

	if(match.size() >= n){
		cout << "Matching" << endl;
		for(int i = 0; i < n; i++) cout << match[i] << ' ';
	} else{
		cout << "IndSet" << endl;
		for(int i = 1, cnt = 0; i < 3*n and cnt < n; i++){
			if(!vis[i]) cout << i << ' ', cnt++;
		}
	}

	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
