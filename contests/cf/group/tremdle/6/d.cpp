#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 32, MOD = 1e9+7, LOG = ceil(log2(MAX));

namespace seg {
	ll seg[2*MAX], lazy[2*MAX];
	int n;

	ll junta(ll a, ll b) {
		return min(a, b);
	}

	// soma x na posicao p de tamanho tam
	void poe(int p, ll x, int tam, bool prop=1) {
		seg[p] += x;
		if (prop and p < n) lazy[p] += x;
	}

	// atualiza todos os pais da folha p
	void sobe(int p) {
		for (int tam = 2; p /= 2; tam *= 2) {
			seg[p] = junta(seg[2*p], seg[2*p+1]);
			poe(p, lazy[p], tam, 0);
		}
	}

	// propaga o caminho da raiz ate a folha p
	void prop(int p) {
		int tam = 1 << (LOG-1);
		for (int s = LOG; s; s--, tam /= 2) {
			int i = p >> s;
			if (lazy[i]) {
				poe(2*i, lazy[i], tam);
				poe(2*i+1, lazy[i], tam);
				lazy[i] = 0;
			}
		}
	}

	void build(int n2, int* v) {
		n = n2;
		for (int i = 0; i < n; i++) seg[n+i] = v[i];
		for (int i = n-1; i; i--) seg[i] = junta(seg[2*i], seg[2*i+1]);
		for (int i = 0; i < 2*n; i++) lazy[i] = 0;
	}

	ll query(int a, int b) {
		ll ret = LINF;
		for (prop(a+=n), prop(b+=n); a <= b; ++a/=2, --b/=2) {
			if (a%2 == 1) ret = junta(ret, seg[a]);
			if (b%2 == 0) ret = junta(ret, seg[b]);
		}
		return ret;
	}

	void update(int a, int b, int x) {
		int a2 = a += n, b2 = b += n, tam = 1;
		for (; a <= b; ++a/=2, --b/=2, tam *= 2) {
			if (a%2 == 1) poe(a, x, tam);
			if (b%2 == 0) poe(b, x, tam);
		}
		sobe(a2), sobe(b2);
	}
};

int N;

int brute(){
	int i = 0;
	while(i < N and seg::query(i, i) == 0) i++;
	if(i == N) return 0;
	cerr << i << endl;

	int mi = LINF;
	for(int j = i; j < N and seg::query(j, j); j++){
		int prev = seg::query(i, j);
		seg::update(i, j, -prev);
		mi = min(mi, 1+brute());
		seg::update(i, j, prev);
	}
	
	return mi;
}

void solve(){
	cin >> N;
	set<int> st;
	int v[N]; for(int i = 0; i < N; i++) cin >> v[i], st.insert(v[i]);

	int k = 1;
	map<int, int> mp;
	for(auto x: st) mp[x] = k++;

	for(int i = 0; i < N; i++) v[i] = mp[v[i]];
	
	seg::build(N, v);

	cout << brute() << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
