#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
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

int n;

vector<vl> mult(vector<vl> a, vector<vl> b){
    vector<vl> ans(n, vl(n));
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) ans[i][j] += a[i][k]*b[k][j], ans[i][j] %= MOD;
    return ans;
}

vector<vl> fexp(vector<vl> a, ll b){
    vector<vl> ans(n, vl(n)); rep(i, 0, n) ans[i][i] = 1;
    while(b){
        if(b&1) ans = mult(ans, a);
        a = mult(a, a), b >>= 1;
    }
    return ans;
}

void solve(){
    ll k; cin >> n >> k;

    vector<vl> mat(n, vl(n));
    forr(x, mat) forr(y, x) cin >> y;

    vector<vl> res = fexp(mat, k);

    ll ans = 0;
    forr(x, res) forr(y, x) ans += y, ans %= MOD;
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
