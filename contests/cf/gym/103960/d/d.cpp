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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;


void solve(){
    int n, x, y; cin >> n >> x >> y;
    int lim = 1<<n;
    int px = 1<<(n-1), py = 1<<(n-1);

    int l = 0, r = lim, ansx = 0, ansy = 0;
    while(l <= r){
        int m = (l+r)/2;
        if(m == x) break;
        ansx++;
        if(m <= x) l = m;
        else r = m;
    }
    l = 0, r = lim;
    while(l <= r){
        int m = (l+r)/2;
        if(m == y) break;
        ansy++;
        if(m < y) l = m;
        else r = m;
    }

    cout << max(ansx, ansy) << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
