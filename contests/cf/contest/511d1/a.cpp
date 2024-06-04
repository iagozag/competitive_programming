#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void DBG() {
    cerr << "]" << endl;
}

void DBGC() {
    cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t)) cerr << ", ";
    DBG(t...);
}

template<class H, class... T> void DBGC(H h, T... t) {
    for(auto& x: h) cerr << x << " ";
    if(sizeof...(t)) cerr << "], [ ";
    DBGC(t...);
}

#ifndef _DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
#else
#define dbg(...) 0
#define dbgc(...) 0
#endif

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 1.5e7+10, MOD = 1e9+7;

int divi[MAX];

void sieve(){
    rep(i, 1, MAX) divi[i] = 1;

    for(int i = 2; i < MAX; i++) if(divi[i] == 1){
        for(ll j = ll(i)*i; j < MAX; j += i) divi[j] = i;
        divi[i] = i;
    }
}

set<int> fact(int x){
    set<int> primes;
    while(x > 1){
        primes.insert(divi[x]);
        x /= divi[x];
    }
    return primes;
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve(){
    int n, g; cin >> n;
    vi v(n); g = v[0]; forr(x, v) cin >> x, g = gcd(g, x);

    sieve();

    forr(x, v) x /= g;

    map<int,int> cnt;
    rep(i, 0, n){
        set<int> div = fact(v[i]);
        forr(x, div) cnt[x]++;
    }

    int ans = n;
    forr(x, cnt) ans = min(ans, n-x.ss);
    cout << (ans == n ? -1 : ans) << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
