#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, MOD = 1e9+7, LOG = ceil(log2(MAX));

struct matrix {
	int n, m;
	int mat[2][2];

	matrix(int n_ = 0, int m_ = 0, bool ident = false) :
			n(n_), m(m_) {
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) mat[i][j] = 0;
		if (ident) {
			assert(n == m);
			mat[0][0] = mat[1][1] = 1;
		}
	}
	matrix(const vector<vector<int>>& c) :
		n(c.size()), m(c[0].size()) {
			for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) mat[i][j] = c[i][j];
	}
	matrix(const initializer_list<initializer_list<int>>& c) {
		vector<vector<int>> val;
		for (auto& i : c) val.push_back(i);
		*this = matrix(val);
	}

	bool is_ident(){
		return mat[0][0] == 1 and mat[1][1] == 1 and !mat[0][1] and !mat[1][0];
	}

	matrix operator*(matrix& r) const {
		assert(m == r.n);
		matrix M(n, r.m);
		for (int i = 0; i < n; i++) for (int k = 0; k < m; k++)
			for (int j = 0; j < r.m; j++) {
				int add = mat[i][k] * r.mat[k][j];
				M.mat[i][j] += add%MOD;
				if (M.mat[i][j] >= MOD) M.mat[i][j] -= MOD;
			}
		return M;
	}
	matrix operator+(matrix& r) {
		assert(n == r.n and m == r.m);
		matrix M(n, m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
				M.mat[i][j] = mat[i][j] + r.mat[i][j];
				if (M.mat[i][j] >= MOD) M.mat[i][j] -= MOD;
			}
		return M;
	}
	matrix operator^(ll e){
		matrix M(n, n, true), at = *this;
		while (e) {
			if (e&1) M = M*at;
			e >>= 1;
			at = at*at;
		}
		return M;
	}
};

matrix F({{1, 1}, {1, 0}});

matrix fib(int x){
	matrix base({{1}, {0}});

	matrix e = F^(x-1);
	return e*base;
}

int n, q;
matrix v[MAX];

namespace seg {
	matrix seg[2*MAX], lazy[2*MAX];

	// soma x na posicao p de tamanho tam
	void poe(int p, matrix& x, bool prop=1) {
		seg[p] = x*seg[p];
		if (prop and p < n) lazy[p] = x*lazy[p];
	}

	// atualiza todos os pais da folha p
	void sobe(int p) {
		for (int tam = 2; p /= 2; tam *= 2) {
			seg[p] = seg[2*p]+seg[2*p+1];
			poe(p, lazy[p], 0);
		}
	}

	// propaga o caminho da raiz ate a folha p
	void prop(int p) {
		int tam = 1 << (LOG-1);
		for (int s = LOG; s; s--, tam /= 2) {
			int i = p >> s;
			if (!lazy[i].is_ident()) {
				poe(2*i, lazy[i]);
				poe(2*i+1, lazy[i]);
				lazy[i] = matrix(2, 2, true);
			}
		}
	}

	void build() {
		for (int i = 0; i < n; i++) seg[n+i] = v[i];
		for (int i = n-1; i; i--){
			seg[i] = seg[2*i]+seg[2*i+1];
		}
		for (int i = 0; i < 2*n; i++) lazy[i] = matrix(2, 2, true);
	}

	matrix query(int a, int b) {
		matrix ret = matrix(2, 1);
		for (prop(a+=n), prop(b+=n); a <= b; ++a/=2, --b/=2) {
			if (a%2 == 1) ret = ret+seg[a];
			if (b%2 == 0) ret = ret+seg[b];
		}
		return ret;
	}

	void update(int a, int b, matrix& x) {
		int a2 = a += n, b2 = b += n, tam = 1;
		for (; a <= b; ++a/=2, --b/=2, tam *= 2) {
			if (a%2 == 1) poe(a, x);
			if (b%2 == 0) poe(b, x);
		}
		sobe(a2), sobe(b2);
	}
};

void solve(){
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		v[i] = fib(x);
	}

	seg::build();

	for(int i = 0; i < q; i++){
		int op, l, r; cin >> op >> l >> r; --l, --r;
		if(op == 1){
			int x; cin >> x;

			matrix M = F^x;

			seg::update(l, r, M);
		} else{
			cout << seg::query(l, r).mat[0][0] << endl;
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}


