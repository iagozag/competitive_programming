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

vi v, seg;

int build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = v[tl];

    int tm = (tl+tr)>>1;
    return seg[node] = build(node*2, tl, tm) + build(node*2+1, tm+1, tr);
}

int update(int node, int tl, int tr, int idx){
    if(idx < tl || idx > tr) return seg[node];
    if(tl == tr) return seg[node] = !seg[node];

    int tm = (tl+tr)>>1;
    return seg[node] = update(node*2, tl, tm, idx) + update(node*2+1, tm+1, tr, idx);
}

int query(int node, int tl, int tr, int x){
    if(tl == tr) return tl;

    int tm = (tl+tr)>>1;

    if(seg[node] <= x){
        if(seg[node*2] != 0 && seg[node*2+1] == 0) return query(node*2, tl, tm, x);
        return query(node*2+1, tm+1, tr, x);
    }

    if(seg[node]*2 >= x) return query(node*2, tl, tm, x);
    return query(node*2+1, tm+1, tr, x);
}

void solve(){
    int n, m; cin >> n >> m;
    v = vi(n), seg = vi(4*n);
    for(int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n-1);
    
    for(int i = 0; i < m; i++){
        int op, a; cin >> op;
        if(op == 1) { cin >> a; update(1, 0, n-1, a); }
        else{ cin >> a; cout << query(1, 0, n-1, a) << endl; }
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

