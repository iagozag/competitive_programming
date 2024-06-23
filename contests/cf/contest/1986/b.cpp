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

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> v(n, vi(m));
    rep(i, 0, n) rep(j, 0, m) cin >> v[i][j];

    vector<pii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    rep(i, 0, n) rep(j, 0, m){
        int ma = 0;
        for(auto [a, b]: moves){
            a += i, b += j;
            if(a < 0 or a >= n or b < 0 or b >= m) continue;
            ma = max(ma, v[a][b]);
        }
        if(v[i][j] > ma) v[i][j] = ma;
    }

    rep(i, 0, n) rep(j, 0, m) cout << v[i][j] << " \n"[j==m-1];
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
