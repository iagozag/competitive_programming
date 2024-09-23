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
void yes(ll ans){
    string s = to_string(ans);
    while(sz(s) < 6) s = '0'+s;
    cout << s << endl;
}

const int MAX = 2e5+10, MOD = 1e6;

vector<vl> mult(vector<vl> a, vector<vl> b){
    vector<vl> ans(sz(a), vl(sz(b[0])));
    rep(i, 0, sz(a)) rep(j, 0, sz(a[0])) rep(k, 0, sz(b[0]))
        ans[i][j] += a[i][k]%MOD*b[k][j]%MOD, ans[i][j] %= MOD;

    return ans;
}

vector<vl> fexp(vector<vl> a, ll b){
    vector<vl> ans(3, vl(3)); rep(i, 0, 3) ans[i][i] = 1;
    while(b){
        if(b&1) ans = mult(ans, a);
        a = mult(a, a), b >>= 1;
    }
    return ans;
}

void solve(){
    ll n, k, l; cin >> n >> k >> l; n /= 5, k %= MOD, l %= MOD;
    
    if(n == 1) return yes(k);
    else if(n == 2) return yes((k*k%MOD+l)%MOD);

    vector<vl> mat{{k, l, 0}, {1, 0, 0}, {0, 1, 0}}; 
    vector<vl> mat2{{(k*k%MOD+l)%MOD, 0, 0}, {k, 0, 0}, {1, 0, 0}}; 
    

    mat = fexp(mat, n-2);
    mat = mult(mat, mat2);

    return yes(mat[0][0]);
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
