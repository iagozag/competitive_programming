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

#ifdef _DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
#else
#define dbg(...) 0
#define dbgc(...) 0
#endif

int MAX = 1e5+10;
vi v(MAX), lz(MAX);
vector<ii> seg(4*MAX);

ii combine(ii a, ii b){
    if(a.s > b.s) return a;
    if(b.s > a.s) return b;
    if(a.f == b.f) return {a.f, a.s+b.s};
    return (a.f > b.f) ? a : b;
}

ii build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = {v[tl], 1};

    int tm = (tl+tr)>>1;
    return seg[node] = combine(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

void unlazy(int node, int tl, int tr){
    if(lz[node] != 0){
        seg[node].f += (tr-tl+1) * lz[node];
        seg[node].s = 1;
        if(tl != tr){
            lz[node*2] += lz[node];
            lz[node*2+1] += lz[node];
        }
        lz[node] = 0;
    }
}

void updateRange(int node, int tl, int tr, int idxl, int idxr, int val){
    unlazy(node, tl, tr);

    if(tl > idxr || tr < idxl) return;
    if(tl == tr) seg[node] = {(seg[node].f + val)%9, 1};

    int tm = (tl+tr)>>1;

}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> v[i];
    ii max = build(1, 0, n-1);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        ii tmp = updateRange(1, 0, n-1, a, b, max.f);
        max = tmp;
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

