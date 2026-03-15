#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

// Matriz

#define MODULAR true
struct matrix : vector<vector<int>> {
	int n, m;

	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << (*this)[i][j] << " ";
			cout << endl;
		}
	}

	matrix() {n = m = 0; }

	matrix(int n_, int m_, bool ident = false) :
			vector<vector<int>>(n_, vector<int>(m_, 0)), n(n_), m(m_) {
		if (ident) {
			assert(n == m);
			for (int i = 0; i < n; i++) (*this)[i][i] = 1;
		}
	}
	matrix(const vector<vector<int>>& c) : vector<vector<int>>(c),
		n(c.size()), m(c[0].size()) {}
	matrix(const initializer_list<initializer_list<int>>& c) {
		vector<vector<int>> val;
		for (auto& i : c) val.push_back(i);
		*this = matrix(val);
	}

	matrix operator*(matrix& r) {
		assert(m == r.n);
		matrix M(n, r.m);
		for (int i = 0; i < n; i++) for (int k = 0; k < m; k++)
			for (int j = 0; j < r.m; j++) {
				ll add = (ll)(*this)[i][k] * r[k][j];
#if MODULAR
				M[i][j] += add%MOD;
				if (M[i][j] >= MOD) M[i][j] -= MOD;
#else
				M[i][j] += add;
#endif
			}
		return M;
	}
	matrix operator+(matrix& r) {
		assert(m == r.m and n == r.n);
		matrix M(n, m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
				int add = (*this)[i][j] + r[i][j];
#if MODULAR
				M[i][j] = add;
				if (M[i][j] >= MOD) M[i][j] -= MOD;
#else
				M[i][j] = add;
#endif
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
	void apply_transform(matrix M, ll e){
		auto& v = *this;
		while (e) {
			if (e&1) v = M*v;
			e >>= 1;
			M = M*M;
		}
	}
};

int msb(int x){ return __builtin_clz(1)-__builtin_clz(x); }

matrix M, B;
matrix pot[32];

void f(int n, matrix& sum){
	if(!n) return;

	int bit = msb(n);
	n -= (1<<bit);
	matrix mrest = M^n, ss = pot[bit]*mrest;
	sum = sum+ss;

	f(n, sum);
}

void solve(){
	int n, x, m; cin >> n >> x >> m; x--;
	M = matrix(n, n), B = matrix(n, 1);
	B[x][0] = 1;
	for(int i = 0; i < n; i++){
		if(i) M[i][i-1] = 1;
		if(i+1 < n) M[i][i+1] = 1;
	}

	matrix sq = M^2;
	pot[0] = M, pot[1] = M + sq; matrix pp = M;
	for(int i = 2; i <= msb(m); i++){
		matrix mult(n, n, true);
		pp = pp*pp;
		mult = mult + pp;
		pot[i] = pot[i-1]*mult;
	}

	matrix sum(n, n), ident(n, n, true);
	f(m, sum);
	sum = sum+ident;

	matrix ans = sum*B;
	for(int i = 0; i < n; i++) cout << ans[i][0] << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
