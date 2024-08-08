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

void no(){ cout << "-1" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vl v(n); forr(x, v) cin >> x;
    ll ma = 0;
    rep(i, 0, n){
        ckmax(ma, v[i]);
        if(v[i] == 1 and ma > 1) return no();
    }

    vl exp(n, 0);
    rep(i, 1, n){
        if(v[i-1] == 1) continue;

        exp[i] = exp[i-1];
        ll need = 0;
        if(v[i] >= v[i-1]){
            ll t1 = v[i-1];
            while(t1 <= v[i]) need++, t1 *= t1;
            exp[i] -= need-1;
        } else if(v[i] < v[i-1]){
            ll t1 = v[i];
            while(t1 < v[i-1]) need++, t1 *= t1;
            exp[i] += need;
        } else exp[i] = exp[i-1];
        ckmax(exp[i], 0LL);
    }


    ll sum = 0;
    forr(x, exp) sum += x;
    cout << sum << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
