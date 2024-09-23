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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> sett;

const int MAX = 2e5+10, MOD = 1e9+7;

ll x, y, h, l;

void solve(){
    cin >> x >> y >> h >> l;
    ll cnt = h*l+h+l+1;

    vector<pll> v(h);
    rep(i, 0, h){
       ll a, b; cin >> a >> b;
       v[i] = {a, b};
    }
    sort(all(v));
    rep(i, 0, h) swap(v[i].ff, v[i].ss);

    sett s;
    rep(i, 0, h){
        cnt += (ll)sz(s)-(ll)s.order_of_key(v[i].ff);
        s.insert(v[i].ff);
    }

    s.clear(), v = vector<pll>(l);
    rep(i, 0, l){
       ll a, b; cin >> a >> b;
       v[i] = {a, b};
    }
    sort(all(v));
    rep(i, 0, l) swap(v[i].ff, v[i].ss);

    rep(i, 0, l){
        cnt += (ll)sz(s)-(ll)s.order_of_key(v[i].ff);
        s.insert(v[i].ff);
    }
    
    cout << cnt << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
