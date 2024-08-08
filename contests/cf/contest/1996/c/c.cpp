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

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    vector<vi> la(n+1, vi(26)), lb(n+1, vi(26));
    rep(i, 1, n+1){ la[i] = la[i-1]; la[i][a[i-1]-'a']++; }
    rep(i, 1, n+1){ lb[i] = lb[i-1]; lb[i][b[i-1]-'a']++; }

    rep(j, 0, m){
        int c, d; cin >> c >> d;
        --c;
        vi va = la[d], vb = lb[d]; 
        rep(i, 0, 26) va[i] -= la[c][i], vb[i] -= lb[c][i];
        int ans = 0;
        rep(i, 0, 26) ans += abs(va[i]-vb[i]);
        cout << ans/2 << endl;
    }
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
