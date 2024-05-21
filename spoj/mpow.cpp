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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vector<vl> v;

vector<vl> mult(vector<vl> a, vector<vl> b){
    int n = a.size(); vector<vl> ans(n, vl(n));
    rep(i, 0, n) rep(j, 0, n){
        rep(k, 0, n) ans[i][j] += (a[i][k]%MOD)*(b[k][j]%MOD), ans[i][j] %= MOD;
    }
    return ans;
}

vector<vl> fexp(vector<vl> mat, int k){
    int n = mat.size(); vector<vl> ans(n, vl(n)); rep(i, 0, n) ans[i][i] = 1;
    while(k){
        if(k&1) ans = mult(ans, mat);
        mat = mult(mat, mat);
        k >>= 1;
    }
    return ans;
}

void solve(){
    int n, k; cin >> n >> k;
    v = vector<vl>(n, vl(n));
    rep(i, 0, n) rep(j, 0, n) cin >> v[i][j];

    vector<vl> ans = fexp(v, k);

    rep(i, 0, n) rep(j, 0, n) cout << ans[i][j] << " \n"[j == n-1]; 
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
