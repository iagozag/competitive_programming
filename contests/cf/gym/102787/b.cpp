#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int m_ = 27;
int fexp(int x, int y) {
    int ans = 1;
    while(y){
        if(y&1) ans = ans*x%MOD;
        x = x*x%MOD;
        y >>= 1;
    }
    return ans;
}

struct Value {
    int hash, rhash, size;

    Value operator+(const Value& oth) const {
        Value res {};
        res.hash = ((hash * fexp(m_, oth.size)) % MOD + oth.hash) % MOD;
        res.rhash = (rhash + (oth.rhash * fexp(m_, size)) % MOD) % MOD;
        res.size = size + oth.size;
        return res;
    }
};

struct node {
	node *l, *r;
	int p, sz;
	Value val, agg;
	node(Value v) : l(NULL), r(NULL), p(rng()), sz(1), val(v), agg(v) {}

	void update() {
		sz = 1, agg = val;
		if (l) sz += l->sz, agg = l->agg + agg;
		if (r) sz += r->sz, agg = agg + r->agg;
	}

	~node() {
        delete l;
        delete r;
    }
};

node* root = NULL;

int size(node* x) { return x ? x->sz : 0; }

void join(node* l, node* r, node*& i) { // assume que l < r
	if (!l or !r) return void(i = l ? l : r);
	if (l->p > r->p) join(l->r, r, l->r), i = l;
	else join(l, r->l, r->l), i = r;
	i->update();
}

void split(node* i, node*& l, node*& r, int v, int key = 0) {
	if (!i) return void(r = l = NULL);
	if (key + size(i->l) < v) split(i->r, i->r, r, v, key+size(i->l)+1), l = i;
	else split(i->l, l, i->l, v, key), r = i;
	i->update();
}

void push_back(int v) {
	node* i = new node({v, v, 1});
	join(root, i, root);
}

Value query(int l, int r) {
	node *L, *M, *R;
	split(root, M, R, r+1), split(M, L, M, l);
	Value ans = M->agg;
	join(L, M, M), join(M, R, root);
	return ans;
}

void update(int l, int r, int s) {
	node *L, *M, *R;
	split(root, M, R, r+1), split(M, L, M, l);
	join(L, M, M), join(M, R, root);
}

void reverse(int l, int r) {
	node *L, *M, *R;
	split(root, M, R, r+1), split(M, L, M, l);
	join(L, M, M), join(M, R, root);
}

void solve(){
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++){ char c; cin >> c; push_back((int)(c-'a'+1)); }

	for(int i = 0; i < q; i++){
		int op; cin >> op;
		if(op == 1){
			int a, b; cin >> a >> b; --a, --b; n -= b-a+1;

			node *l, *m, *r, *tmp;
			split(root, m, r, b+1);
			split(m, l, m, a);

			join(l, r, tmp);
			root = tmp;
		} else if(op == 2){
			char c; int p; cin >> c >> p; --p; n++;

			node *m = new node({(int)(c-'a'+1), (int)(c-'a'+1), 1});

			node *l, *r, *tmp;
			split(root, l, r, p);

			join(l, m, l);
			join(l, r, tmp);

			root = tmp;
		} else{
			int a, b; cin >> a >> b; --a, --b;
			Value ans = query(a, b);
			cout << (ans.hash == ans.rhash ? "yes" : "no") << endl;
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
