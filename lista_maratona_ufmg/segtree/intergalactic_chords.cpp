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

vi v, lz;
vector<vi> seg;

vi combine(vi a, vi b){
    vi tmp(9);
    for(int i = 0; i < 9; i++)
        tmp[i] = a[i] + b[i];

    return tmp;
}

vi build(int node, int tl, int tr){
    if(tl == tr){
        vi tmp(9); tmp[1]++;;
        return seg[node] = tmp;
    }

    int tm = (tl+tr)>>1;
    return seg[node] = combine(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

void unlazy(int node, int tl, int tr){
    if(lz[node]){
        rotate(seg[node].begin(), seg[node].begin()+seg[node].size()-lz[node], seg[node].end()); 
        if(tl != tr){
            lz[node*2] += lz[node];
            lz[node*2+1] += lz[node];
        }
        lz[node] = 0;
    }
}

void update(int node, int tl, int tr, int a, int b, int val){
    unlazy(node, tl, tr);

    if(tl > b || tr < a) return;
    if(a <= tl && b >= tr){
        lz[node] += val;
        unlazy(node, tl, tr);
    } else{
        int tm = (tl+tr)>>1;
        update(node*2, tl, tm, a, b, val);
        update(node*2+1, tm+1, tr, a, b, val);

        seg[node] = combine(seg[node*2], seg[node*2+1]);
    }
}

vi query(int node, int tl, int tr, int a, int b){
    unlazy(node, tl, tr);

    if(b < tl || a > tr) return vi(9);
    if(a <= tl && tr <= b) return seg[node];

    int tm = (tl+tr)>>1;
    return combine(query(node*2, tl, tm, a, b), query(node*2+1, tm+1, tr, a, b));
}

int max(vi& tmp){
    int max = tmp[0], idx = 0;
    for(int i = 1; i < 9; i++)
        if(max < tmp[i]) max = tmp[i], idx = i;

    return idx;
}

void solve(){
    int n, m; cin >> n >> m;
    v = vi(n, 1), lz = vi(4*n), seg = vector<vi>(4*n);
    vi q = build(1, 0, n-1);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;

        cout << "input: " << a << " " << b << endl;
        vi q = query(1, 0, n-1, a, b); 
        dbgc(q); int maxi = max(q);
        cout << "max rp: " << maxi << endl;
        update(1, 0, n-1, a, b, maxi);
    }

    dbgc(lz); 
    for(int i = 0; i < n; i++) cout << max(seg[i]) << endl;
}

int main(){ // _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

