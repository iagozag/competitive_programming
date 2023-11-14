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

int MAX = 2e5+10;
vector<ii> seg(4*MAX), v(MAX);

ii combine(ii a, ii b){
    return {max(a.f, b.f), min(a.s, b.s)};
}

ii build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = v[tl];

    int tm = (tl+tr)>>1;
    return seg[node] = combine(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

ii update(int node, int tl, int tr, int idx, ii val){
    if(idx < tl || idx > tr) return seg[node];
    if(tl == tr) return seg[node] = val;

    int tm = (tl+tr)>>1;
    return seg[node] = combine(update(node*2, tl, tm, idx, val), update(node*2+1, tm+1, tr, idx, val));
}

ii query(int node, int tl, int tr, int a, int b){
    if(a > tr || b < tl) return {-INF, INF};
    if(a <= tl && b >= tr) return seg[node];

    int tm = (tl+tr)>>1;
    return combine(query(node*2, tl, tm, a, b), query(node*2+1, tm+1, tr, a, b));
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){ int a, b; cin >> a >> b; v[i] = {a, b}; }
    build(1, 0, n-1);

    for(int i = 0; i < m; i++){
        char op; int a, b, c; cin >> op;
        if(op == '?'){
            cin >> a >> b; a--, b--;
            auto [x, y] = query(1, 0, n-1, a, b);
            cout << ((x <= y) ? abs(x-y)+1 : 0) << endl;
        } else{
            cin >> a >> b >> c; a--;
            update(1, 0, n-1, a, {b, c});
        }
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

