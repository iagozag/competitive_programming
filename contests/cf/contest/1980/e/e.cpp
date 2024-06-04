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
    vector<vi> a(n, vi(m)), b(n, vi(m));
    rep(i, 0, n){
        rep(j, 0, m){
            int x; cin >> x;
            a[i][j] = x;
        }
    }
    rep(i, 0, n){
        rep(j, 0, m){
            int x; cin >> x;
            b[i][j] = x;
        }
    }

    vector<set<int>> rows(n), cols(m);
    rep(i, 0, n) rep(j, 0, m)
        rows[i].insert(a[i][j]);
    rep(i, 0, m) rep(j, 0, n)
        cols[i].insert(a[j][i]);

    vector<set<int>> rows2(n), cols2(m);
    rep(i, 0, n) rep(j, 0, m)
        rows2[i].insert(b[i][j]);
    rep(i, 0, m) rep(j, 0, n)
        cols2[i].insert(b[j][i]);

    sort(all(rows)), sort(all(cols)), sort(all(rows2)), sort(all(cols2));
    if(rows == rows2 and cols == cols2) return yes();
    return no();
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
