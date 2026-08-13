#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, UPD = 1e5+10, LOG = 18;
const int MAXS = 2*MAX+UPD*LOG;

namespace perseg {
	ll seg[MAXS];
	int rt[UPD], L[MAXS], R[MAXS], cnt, t;
	int n, *v;

	ll build(int p, int l, int r) {
		if (l == r) return seg[p] = v[l];
		L[p] = cnt++, R[p] = cnt++;
		int m = (l+r)/2;
		return seg[p] = min(build(L[p], l, m), build(R[p], m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		rt[0] = cnt++;
		build(0, 0, n-1);
	}
	ll query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return INF;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return min(query(a, b, L[p], l, m), query(a, b, R[p], m+1, r));
	}
	ll query(int a, int b, int tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	ll update(int a, int x, int lp, int p, int l, int r) {
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		if (a <= m)
			return seg[p] = min(update(a, x, L[lp], L[p]=cnt++, l, m), seg[R[p]=R[lp]]);
		return seg[p] = min(seg[L[p]=L[lp]], update(a, x, R[lp], R[p]=cnt++, m+1, r));
	}
	int update(int a, int x, int tt=t) {
		update(a, x, rt[tt], rt[++t]=cnt++, 0, n-1);
		return t;
	}
};

int a[MAX];
vector<int> g[MAX];
vector<int> dep[MAX];
int dd[MAX], child[MAX], pos[MAX];
vector<int> euler;

int euler_path(int v, int p, int d){
	pos[v] = euler.size();
	euler.emplace_back(v);
	dep[d].emplace_back(v);
	dd[v] = d, child[v] = 1;
	for(auto ve: g[v]) if(ve != p) child[v] += euler_path(ve, v, d+1);
	return child[v];
}

void solve(){
	int n, r; cin >> n >> r; --r;
	for(int i = 0; i < n; i++) cin >> a[i];

	for(int i = 0; i < n-1; i++){
		int aa, b; cin >> aa >> b; --aa, --b;
		g[aa].emplace_back(b), g[b].emplace_back(aa);
	}

	euler_path(r, r, 0);

	int init[n]; fill(&init[0], &init[0]+n, LINF);
	init[pos[r]] = a[r];
	perseg::build(n, init);

	int d = 1; vector<int> idx = {0};
	while(dep[d].size()){
		for(auto x: dep[d]) perseg::update(pos[x], a[x]);
		idx.emplace_back(idx.back()+dep[d].size());
		d++;
	}

	int qq, ans = 0; cin >> qq;
	for(int i = 0; i < qq; i++){
		int p, q; cin >> p >> q;
		int x = (p+ans)%n, k = (q+ans)%n;

		int depth = dd[x], down = depth+k;
		int t = idx[min(down, d-1)];

		ans = perseg::query(pos[x], pos[x]+child[x]-1, t);

		cout << ans << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
