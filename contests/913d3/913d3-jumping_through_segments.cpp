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

int MAX = 2e5+10;
vector<ii> v;

bool check(int k){
    ii dist = {0, 0};
    for(size_t i = 0; i < v.size(); i++){
        if(dist.s < v[i].f && dist.s+k < v[i].f) return false;
        else if(dist.f > v[i].s && dist.f-k > v[i].s) return false;
        
        dist = {max(v[i].f, dist.f-k), min(v[i].s, dist.s+k)};
    }

    return true;
}

void solve(){
    int n; cin >> n;
    v = vector<ii>(n);
    for(int i = 0; i < n; i++) cin >> v[i].f >> v[i].s;

    int l = 0, r = 1e9+10, ans;
    while(l <= r){
        int m = l+(r-l)/2;
        if(check(m)) ans = m, r = m-1;
        else l = m+1;
    }

    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

