#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
#define pb push_back

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

int n, k, MAX = 110;
vector<int[4]> v;

bool check(int x){
    ll sum = 0;
    for(auto& y: v){
        if(y[1] >= x) continue;

        if(y[3] <= x) sum += (v[2]-v[0])*(y[3]-y[1]);
        else sum += (v[2]-v[0])*(x-y[1]);

        if(sum >= k) return true;
    }

    return false;
}

void solve(){
    cin >> n >> k; v = vector<int[4]>(n);
    for(auto& x: v) cin >> x[0] >> x[1] >> x[2] >> x[3];

    int l = 0, r = 1e9+10; ll ans = -1;
    while(l <= r){
        int m = l+(r-l)/2;
        if(check(m)) ans = m, r = m-1;
        else l = m+1;
    }

    if(ans == -1) cout << "PERDAO MEU REI" << endl;
    else cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

