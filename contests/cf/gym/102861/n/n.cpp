#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 1e7+10, MOD = 1e9+7;

ll mul(ll a, ll b, ll m) {
	ll ret = a*b - ll((long double)1/m*a*b+0.5)*m;
	return ret < 0 ? ret+m : ret;
}

ll pow(ll x, ll y, ll m) {
	if (!y) return 1;
	ll ans = pow(mul(x, x, m), y/2, m);
	return y%2 ? mul(x, ans, m) : ans;
}

bool prime(ll n) {
	if (n < 2) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0) return 0;

	ll r = __builtin_ctzll(n - 1), d = n >> r;
	for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		ll x = pow(a, d, n);
		if (x == 1 or x == n - 1 or a % n == 0) continue;
		
		for (int j = 0; j < r - 1; j++) {
			x = mul(x, x, n);
			if (x == n - 1) break;
		}
		if (x != n - 1) return 0;
	}
	return 1;
}

ll rho(ll n) {
	if (n == 1 or prime(n)) return n;
	auto f = [n](ll x) {return mul(x, x, n) + 1;};

	ll x = 0, y = 0, t = 30, prd = 2, x0 = 1, q;
	while (t % 40 != 0 or gcd(prd, n) == 1) {
		if (x==y) x = ++x0, y = f(x);
		q = mul(prd, abs(x-y), n);
		if (q != 0) prd = q;
		x = f(x), y = f(f(y)), t++;
	}
	return gcd(prd, n);
}

vector<ll> fact(ll n) {
	if (n == 1) return {};
	if (prime(n)) return {n};
	ll d = rho(n);
	vector<ll> l = fact(d), r = fact(n / d);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}

void solve(){
    int n, m, k; cin >> m >> n >> k;
    vl v(n);
    forr(x, v) cin >> x;
    rep(i, 0, k){ int a, b, c; cin >> a >> b >> c; }

    set<ll> ans; 

    forr(x, v){
        vl f = fact(x);
        forr(y, f) ans.insert(y);
    }

    forr(x, ans) cout << x << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
