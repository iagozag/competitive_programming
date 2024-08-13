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

void no(){ cout << "N" << endl; }
void yes(){ cout << "Y" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<vi> v(11, vi(11, -1));
    rep(i, 0, n){
        int d, r, c, l; cin >> d >> l >> r >> c;
        if(d == 0){
            if(c+l > 11) return no();
            for(int j = c; j < c+l; j++){
                if(v[r][j] != -1) return no();
                v[r][j] = i;
            }
        } else{
            if(r+l > 11) return no();
            for(int j = r; j < r+l; j++){
                if(v[j][c] != -1) return no();
                v[j][c] = i;
            }
        }
    }
    return yes();
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
