#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

struct Node{
	Node* l;
	Node* r;
	int sum;

	Node(int _sum): l(nullptr), r(nullptr), sum(_sum) {}
	Node(Node* _l, Node* _r): l(_l), r(_r), sum(0) {
		if(l) sum += l->sum;
		if(r) sum += r->sum;
	}
	Node(Node* cp): l(cp->l), r(cp->r), sum(cp->sum) {}
};

int v[MAX], n;
Node* roots[MAX];

Node* build(int l = 0, int r = n-1){
	if(l == r) return new Node(v[l]);

	int m = l+(r-l)/2;
	return new Node(build(l, m), build(m+1, r));
}

Node* update(Node* p, int x, int pos, int l = 0, int r = n-1){
	if(l == r) return new Node(x);

	int m = l+(r-l)/2;
	if(pos <= m) return new Node(update(p->l, x, pos, l, m), p->r);
	return new Node(p->l, update(p->r, x, pos, m+1, r));
}

int query(Node* p, int a, int b, int l = 0, int r = n-1){
	if(a <= l and r <= b) return p->sum;
	if(a > r or b < l) return 0;

	int m = l+(r-l)/2;
	return query(p->l, a, b, l, m)+query(p->r, a, b, m+1, r);
}

void solve(){
	int q; cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> v[i];

	int t = 0;
	roots[t++] = build();

	for(int i = 0; i < q; i++){
		int op; cin >> op;
		if(op == 1){
			int k, a, x; cin >> k >> a >> x; --k, --a;
			roots[k] = update(roots[k], x, a);
		} else if(op == 2){
			int k, a, b; cin >> k >> a >> b; --k, --a, --b;
			cout << query(roots[k], a, b) << endl;
		} else{
			int k; cin >> k; --k;
			roots[t++] = new Node(roots[k]);
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
