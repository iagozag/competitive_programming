#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5e4+10, MOD = 1e9+7;

vector<int> g[MAX];
int c[MAX], d[MAX], ord[MAX], child[MAX];
int nim[MAX][2];

int k = 0;

void dfs(int v, int p){
	ord[v] = k++;
	child[v] = 1;

	nim[v][1] ^= c[v];
	for(auto ve: g[v]) if(ve != p){
		d[ve] = d[v]+1;
		dfs(ve, v);
		child[v] += child[ve];
		nim[v][0] ^= nim[ve][1], nim[v][1] ^= nim[ve][0];
	}
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> c[i];

	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a);
	}

	dfs(0, -1);

	int qq; cin >> qq;
	for(int q = 0; q < qq; q++){
		int a, b; cin >> a >> b; --a, --b;

		if(ord[a] < ord[b] and ord[b] < ord[a]+child[a]){ cout << "INVALID" << endl; continue; }

		int ans = nim[0][0];
		ans ^= nim[a][d[a]&1] ^ nim[a][!(d[b]&1)];

		cout << (ans ? "YES" : "NO") << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
