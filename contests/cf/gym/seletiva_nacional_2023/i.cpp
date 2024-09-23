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
    int a, b; cin >> n;
    
    vector<ii> ans(5);
    int cnt = 0;
    while(a >= 25 and cnt < 3){
        ans[cnt].ff = 25, ans[cnt++].ss = min(23, b), a -= 25, b -= (min(b, 23));
    }
    if(cnt == 3){
        if(a or b){
            if(abs(a-b) == 2) ans[0].ff += a, ans[0].ss += b;
        }
    }




    int qa = 0, qb = 0;
    forr(x, ans){
        if(x.ff == 25 or x.ff == 15 or x.ss == 25 or x.ss == 15){
            if(x.ff > x.ss) qa++;
            else qb++;
        }
    }

    cout << qa << ":" << qb << endl;
    forr(x, ans) cout << x.ff << ":" << x.ss << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
