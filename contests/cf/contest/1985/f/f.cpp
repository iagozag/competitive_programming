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

ll h, n;
vl a, c;

bool good(ll m){
    ll sum = 0;
    rep(i, 0, n){
        sum += a[i]*((m-1)/c[i]+1);
        if(sum >= h) return true;
    }
    return false;
}

void solve(){
    cin >> h >> n;
    a = c = vl(n);
    forr(x, a) cin >> x;
    forr(x, c) cin >> x;

    ll l = 1, r = 2, ans = 0;
    while(!good(r)) l = r, r <<= 1;

    while(l <= r){
        ll m = l+(r-l)/2;
        if(good(m)) ans = m, r = m-1;
        else l = m+1;
    }
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
