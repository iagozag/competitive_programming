#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 510, MOD = 1e9+7;

// Blossom
//
// Matching maximo em grafo geral
//
// O(n^3)
// Se for bipartido, nao precisa da funcao
// 'contract', e roda em O(nm)

vector<int> g[MAX];
int match[MAX]; // match[i] = com quem i esta matchzado ou -1
int n, pai[MAX], base[MAX], vis[MAX];
queue<int> q;

void contract(int u, int v, bool first = 1) {
	static vector<bool> bloss;
	static int l;
	if (first) {
		bloss = vector<bool>(n, 0);
		vector<bool> teve(n, 0);
		int k = u; l = v;
		while (1) {
			teve[k = base[k]] = 1;
			if (match[k] == -1) break;
			k = pai[match[k]];
		}
		while (!teve[l = base[l]]) l = pai[match[l]];
	}
	while (base[u] != l) {
		bloss[base[u]] = bloss[base[match[u]]] = 1;
		pai[u] = v;
		v = match[u];
		u = pai[match[u]];
	}
	if (!first) return;
	contract(v, u, 0);
	for (int i = 0; i < n; i++) if (bloss[base[i]]) {
		base[i] = l;
		if (!vis[i]) q.push(i);
		vis[i] = 1;
	}
}

int getpath(int s) {
	for (int i = 0; i < n; i++) base[i] = i, pai[i] = -1, vis[i] = 0;
	vis[s] = 1; q = queue<int>(); q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i : g[u]) {
			if (base[i] == base[u] or match[u] == i) continue;
			else if (pai[i] == -1) {
				pai[i] = u;
				if (match[i] == -1) return i;
				i = match[i];
				vis[i] = 1; q.push(i);
			}
		}
	}
	return -1;
}

int blossom() {
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int i = 0; i < n; i++) if (match[i] == -1)
		for (int j : g[i]) if (match[j] == -1) {
			match[i] = j;
			match[j] = i;
			ans++;
			break;
		}
	for (int i = 0; i < n; i++) if (match[i] == -1) {
		int j = getpath(i);
		if (j == -1) continue;
		ans++;
		while (j != -1) {
			int p = pai[j], pp = match[p];
			match[p] = j;
			match[j] = p;
			j = pp;
		}
	}
	return ans;
}

void solve(){
	int a, b; cin >> a >> b; n = a+b;
	for(int i = 0; i < a; i++){
		int bb;
		while(cin >> bb and bb){ --bb; g[i].emplace_back(bb+a), g[bb+a].emplace_back(i); }
	}

	cout << blossom() << endl;
	for(int i = 0; i < a; i++) if(match[i] != -1) cout << i+1 << ' ' << match[i]-a+1 << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
