#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
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

const int MAX = 2e5+10;

void solve(){
    ll n, k; cin >> n >> k;
    vector<ii> v(n);
    rep(i, 0, n){ cin >> v[i].ff; }
    rep(i, 0, n){ cin >> v[i].ss; }
    sort(all(v), [&](const ii a, const ii b){
        return abs(a.ss) < abs(b.ss);
    });

    int cnt = 0, i = 0;
    while(i < n){
        if(abs(v[i].ss)-cnt <= 0){ cout << "NO" << endl; return; }
        
        int b = k;
        while(i < n and b > 0){
            if(b >= v[i].ff) b -= v[i].ff, i++;
            else{ v[i].ff -= b; break; }
        }
        cnt++;
    }

    cout << "YES" << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
