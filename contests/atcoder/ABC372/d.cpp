#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

const int LOG = ceil(log2(MAX));

namespace seg {
	ll seg[2*MAX], lazy[2*MAX];
	int n;

	ll junta(ll a, ll b) {
		return a+b;
	}

	// soma x na posicao p de tamanho tam
	void poe(int p, ll x, int tam, bool prop=1) {
		seg[p] += x*tam;
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
		ll ret = 0;
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

void solve(){
    int n; cin >> n;
    vi v(n); forr(x, v) cin >> x;
    
    vi next(n); stack<pii> st; st.push({v[n-1], n-1});
    per(i, n-2, 0){
        if(st.empty()){ st.push({v[i], i}); continue; }
        while(!st.empty() and v[i] > st.top().ff) next[st.top().ss] = i, st.pop();
        st.push({v[i], i});
    }

    int arr[n]; memset(arr, 0, sizeof arr);
    seg::build(n, arr); 
    rep(i, 0, n){
        seg::update(next[i], i-1, 1);
    }

    rep(i, 0, n) cout << seg::query(i, i) << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
