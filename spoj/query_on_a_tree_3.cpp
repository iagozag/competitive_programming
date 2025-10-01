#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1.2e5+10, MOD = 1e9+7;

int n, q;
vector<int> g[MAX];

struct Node{
	Node *l, *r;
	int sum = 0;
	Node(int _sum): sum(_sum) {}
	Node(Node* _l, Node* _r) {
		l = _l, r = _r;

		if(l) sum += l->sum;
		if(r) sum += r->sum;
	}
	Node(Node* cp): l(cp->l), r(cp->r), sum(cp->sum) {}
};

Node* roots[MAX];

Node* build(int l = 0, int r = MAX-1){
	if(l == r) return new Node((int)0);

	int m = l+(r-l)/2;
	return new Node(build(l, m), build(m+1, r));
}

Node* update(Node* p, int pos, int l = 0, int r = MAX-1){
	if(l == r) return new Node(p->sum+1);

	int m = l+(r-l)/2;
	if(pos <= m) return new Node(update(p->l, pos, l, m), p->r);
	return new Node(p->l, update(p->r, pos, m+1, r));
}

int find_kth(Node* vl, Node* vr, int l, int r, int k){
	if(l == r) return l;

	int sl = vl->l->sum, sr = vr->l->sum, tot = sr-sl;
	int m = l+(r-l)/2;

	if(k <= tot) return find_kth(vl->l, vr->l, l, m, k);
	return find_kth(vl->r, vr->r, m+1, r, k-tot);
}

int cnt = 1;
int a[MAX], version[MAX], dp[MAX];

vector<int> euler = {0};

void dfs(int v, int p){
	euler.emplace_back(v);
	for(auto ve: g[v]) if(ve != p) dfs(ve, v), dp[v] += dp[ve]+1;
}

int find_kth(int u, int k){
	int l = version[u]-1; 
	int r = version[u]+dp[u];
	
	return find_kth(roots[l], roots[r], 0, MAX-1, k);
}

void solve(){
	cin >> n; 
	set<int> st; map<int, int> mp, mp_r, mp_idx;
	for(int i = 1; i <= n; i++) cin >> a[i], st.insert(a[i]), mp_idx[a[i]] = i;
	for(int i = 0; i < n-1; i++){ int u, v; cin >> u >> v; g[u].emplace_back(v), g[v].emplace_back(u); }

	roots[0] = build();

	int idx = 0;
	for(auto x: st) mp[x] = idx, mp_r[idx++] = x;
	for(int i = 1; i <= n; i++) a[i] = mp[a[i]];

	memset(dp, 0, sizeof dp);
	dfs(1, 0);

	for(int i = 1; i <= n; i++){
		int v = euler[i];
		version[v] = i;
		roots[i] = new Node(roots[i-1]);
		roots[i] = update(roots[i], a[v]);
	}

	cin >> q;
	for(int i = 0; i < q; i++){
		int u, k; cin >> u >> k;
		cout << mp_idx[mp_r[find_kth(u, k)]] << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
