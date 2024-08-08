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
void yes(int ans){ cout << ans << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

// a, c, b, d
// a, d, b, c

void solve(){
    vi v(4); forr(x, v) cin >> x; 
    vector<vi> pos;
    pos.pb({0, 2, 1, 3}), pos.pb({0, 3, 1, 2});

    int ans = 0;
    rep(i, 0, 2){
        int cnta = 0, cntb = 0;
        if(v[pos[i][0]] > v[pos[i][1]]) cnta++;
        else if(v[pos[i][0]] < v[pos[i][1]]) cntb++;
        if(v[pos[i][2]] > v[pos[i][3]]) cnta++;
        else if(v[pos[i][2]] < v[pos[i][3]]) cntb++;
        
        if(cnta > cntb) ans++;
    }
    cout << ans*2 << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
