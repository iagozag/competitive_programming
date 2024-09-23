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

void no(){ cout << "-1" << endl; }
void yes(int sum){ cout << sum << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;
    vi l(m);

    int k; cin >> k;
    rep(i, 0, k){ int a; cin >> a; --a; l[a] = 1; }

    vector<vi> light(n);
    rep(i, 0, n){
        int mm; cin >> mm;
        rep(j, 0, mm){
            int a; cin >> a; --a;
            light[i].eb(a);
        }
    }

    int sum = k, cnt = 0;
    rep(i, 0, 10){
        rep(j, 0, n){
            if(sum == 0) return yes(cnt);
            rep(kk, 0, sz(light[j])){
                if(l[light[j][kk]]) sum--;
                else sum++;
                l[light[j][kk]] = !l[light[j][kk]];
            }
            cnt++;
        }
    }

    return no();
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
