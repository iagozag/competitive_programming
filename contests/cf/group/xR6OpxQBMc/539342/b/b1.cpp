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

const int MAX = 1e5+10, MOD = 1e9+7;

vector<vi> g(MAX);
vi dist(MAX, -1);

vi fact(MAX);
vi mult(MAX, 1);

void sieve(){
    iota(all(fact), 0);
    fact[0] = fact[1] = -1;
    rep(i, 2, sqrt(MAX)+1) if(fact[i] == i)
        for(int j = i; j < MAX; j += i){ 
            fact[j] = i, mult[j] = 1;
            if((j/i)%i == 0) mult[j] = mult[j/i]+1;
        }
}

int fexp(int a, int b){
    int ans = 1;
    while(b){
        if(b&1) ans *= a;
        a *= a, b >>= 1;
    }
    return ans;
}

int dfs(int v){
    if(dist[v] != -1) return dist[v];

    int ans = 0;
    forr(ve, g[v]) ckmax(ans, dfs(ve));
    return dist[v] = ans+1;
}

void solve(){
    int n; cin >> n;
    vi v(n); forr(x, v) cin >> x;

    vi lastp(1e5+1, -1);

    rep(i, 0, n){
        int t = v[i];
        while(t != 1){
            int x = fact[t];
            if(lastp[x] != -1) g[lastp[x]].eb(i);
            lastp[x] = i, t /= fexp(fact[t], mult[t]);
        }
    }

    int ans = 0;
    rep(i, 0, n) if(dist[i] == -1) ckmax(ans, dfs(i));
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    sieve();

    while(ttt--) solve();

    exit(0);
}
