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
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

ll n, m;
vvb visn, visp, vismn, vismp;

vector<vl> mult(vector<vl> a, vector<vl> b){
    vector<vl> ans(n, vl(n)); visn = vvb(n, vb(n));
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n){
        if(visp[i][k] and vismp[k][j]) visn[i][j] = 1;
        ans[i][j] += (a[i][k]%MOD)*(b[k][j]%MOD), ans[i][j] %= MOD;
    }
    visp = visn;
    return ans;
}

vector<vl> mult2(vector<vl> a, vector<vl> b){
    vector<vl> ans(n, vl(n)); vismn = vvb(n, vb(n));
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n){
        if(vismp[i][k] and vismp[k][j]) vismn[i][j] = 1;
        ans[i][j] += (a[i][k]%MOD)*(b[k][j]%MOD), ans[i][j] %= MOD;
    }
    vismp = vismn;
    return ans;
}

vector<vl> fexp(vector<vl> mat, ll k){
    vector<vl> ans(n, vl(n)); rep(i, 0, n) ans[i][i] = 1, visp[i][i] = 1;
    while(k){
        if(k&1) ans = mult(ans, mat);
        mat = mult2(mat, mat), k >>= 1;
    }
    return ans;
}

void solve(){
    ll k; cin >> n >> m >> k;
    visn = visp = vismn = vismp = vvb(n, vb(n));

    vector<vl> mat(n, vl(n));
    rep(i, 0, m){
        int a, b; cin >> a >> b; --a, --b;
        mat[a][b]++, mat[b][a]++, vismp[a][b] = vismp[b][a] = 1;
    }

    vector<vl> ans = fexp(mat, k);

    rep(i, 0, n) rep(j, i+1, n) cout << (visn[i][j] ? ans[i][j] : -1) << " \n"[j == n-1];
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
