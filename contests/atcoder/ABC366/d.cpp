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

const int MAX = 110, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<vector<vi>> v(n, vector<vi>(n, vi(n)));
    forr(x, v) forr(y, x) forr(z, y) cin >> z;
    int q; cin >> q;

    vector<vector<vi>> pref(n+1, vector<vi>(n+1, vi(n+1)));
    rep(i, 1, n+1) rep(j, 1, n+1) rep(k, 1, n+1)
        pref[i][j][k] = pref[i-1][j][k]+pref[i][j-1][k]+pref[i][j][k-1]-
                        pref[i-1][j-1][k]-pref[i-1][j][k-1]-pref[i][j-1][k-1]+
                        pref[i-1][j-1][k-1]+v[i-1][j-1][k-1];
    
    rep(i, 0, q){
        int lx, rx, ly, ry, lz, rz; cin >> lx >> rx >> ly >> ry >> lz >> rz;
        --lx, --rx, --ly, --ry, --lz, --rz;
        cout << pref[rx+1][ry+1][rz+1]-
                pref[lx][ry+1][rz+1]-pref[rx+1][ly][rz+1]-pref[rx+1][ry+1][lz]+
                pref[rx+1][ly][lz]+pref[lx][ry+1][lz]+pref[lx][ly][rz+1]-
                pref[lx][ly][lz] << endl;
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
