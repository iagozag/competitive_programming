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

void no(){ cout << "*" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void transpose(vector<vi>& mat){
    int n = sz(mat), m = sz(mat[0]);
    vector<vi> t(m, vi(n));
    rep(i, 0, m) rep(j, 0, n) t[i][j] = mat[j][i];
    mat = t;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> mat(n, vi(m));
    rep(i, 0, n) rep(j, 0, m) cin >> mat[i][j];

    int l = 1; vector<pii> org(n*m+1);
    rep(i, 0, n) rep(j, 0, m) org[l++] = {i, j};

    int cnt = 0;
    rep(i, 0, n) rep(j, 0, m){
        if(org[mat[i][j]].ff != i) swap(mat[i], mat[org[mat[i][j]].ff]), cnt++;
    }

    transpose(mat);
    forr(x, org) swap(x.ff, x.ss);

    rep(i, 0, m) rep(j, 0, n){
        if(org[mat[i][j]].ff != i) swap(mat[i], mat[org[mat[i][j]].ff]), cnt++;
    }

    transpose(mat); 

    l = 1;
    rep(i, 0, n) rep(j, 0, m){
        if(mat[i][j] != l++) return no();
    }

    cout << cnt << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
