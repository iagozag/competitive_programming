#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> ans(MAX);

int query(int a, int b){
	if(a == b) return 0;
	cout << "? " << a << ' ' << b << endl;
	int qq; cin >> qq;
	return qq;
}

int msb(int n){ return __builtin_clz(1)-__builtin_clz(n); }

int n;
vector<int> dist;

void f(int root, vector<int> d){
	if(!d.size()) return;

	int c1 = -1, c2 = -1;
	for(auto x: d) if(dist[x] == dist[root]+1){
		if(c1 == -1) c1 = x;
		else c2 = x;
	}

	ans[c1] = ans[c2] = root;

	vector<int> subt1, subt2;
	for(auto x: d) if(x != c1 and x != c2){
		if(query(x, c1) < dist[x]-dist[root]) subt1.emplace_back(x);
		else subt2.emplace_back(x);
	}

	f(c1, subt1), f(c2, subt2);
}

void solve(){
	cin >> n;
	int h = msb(n+1);

	int ma = 0, idx = 1;
	for(int i = 2; i <= n; i++){
		int q = query(1, i);
		if(ma < q) ma = q, idx = i;
	}

	int ot = idx; vector<int> dl(n+1); ma = 0;
	for(int i = 1; i <= n; i++) if(i != idx){
		dl[i] = query(idx, i);
		if(ma < dl[i]) ma = dl[i], ot = i;
	}

	int root = idx;
	for(int i = 1; i <= n; i++) if(i != idx and i != ot){
		if(dl[i] == h-1 and query(i, ot) == h-1){
			root = i;
			break;
		}
	}

	dist = vector<int>(n+1); vector<int> d;
	for(int i = 1; i <= n; i++) if(i != root) dist[i] = query(i, root), d.emplace_back(i);

	f(root, d);

	cout << "! ";
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << endl;
}

int32_t main(){ // _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
