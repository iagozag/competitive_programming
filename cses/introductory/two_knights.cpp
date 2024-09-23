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

const int MAX = 2e5+10, MOD = 1e9+7;

vector<pii> moves = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

int val(int x, int y, int m){
    return x > 0 and x <= m and y > 0 and y <= m;
}

void solve(){
    int n; cin >> n;

    set<set<pii>> st; ll ans = 0;
    rep(k, 1, n+1){
        ans += k*k*(k*k-1)/2;

        rep(i, 1, k+1) for(auto [x, y]: moves)
            if(!st.count(set<pii>({{i, k}, {i+x, k+y}})))
                ans -= val(i+x, k+y, k), st.insert(set<pii>({{i, k}, {i+x, k+y}}));

        rep(j, 1, k+1) for(auto [x, y]: moves)
            if(!st.count(set<pii>({{k, j}, {k+x, j+y}})))
                ans -= val(k+x, j+y, k), st.insert(set<pii>({{k, j}, {k+x, j+y}}));

        cout << ans << endl;
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
