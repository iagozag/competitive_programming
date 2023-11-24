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

const int MAX = 1e5;
typedef pair<int, bitset<MAX>> pp;

vi v; vector<pp> seg;

pp combine(pp a, pp b){
    bitset<MAX> c = a.s | b.s;
    int cnt = a.f + b.f + (a.s&b.s).count();

    return {cnt, c};
}

pp build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = {0, bitset<MAX>().set(v[tl]-1)};

    int tm = (tl+tr)>>1;
    return seg[node] = combine(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

pp query(int node, int tl, int tr, int a, int b){
    if(a > tr || b < tl) return {0, bitset<MAX>()};
    if(a <= tl && b >= tr) return seg[node];

    int tm = (tl+tr)>>1;
    return combine(query(node*2, tl, tm, a, b), query(node*2+1, tm+1, tr, a, b));
}

void solve(){
    int n; cin >> n;
    v = vi(2*n), seg = vector<pp>(8*n);
    map<int,ii> mp;
    for(int i = 0; i < 2*n; i++){
        cin >> v[i];
        if(!mp.count(v[i])) mp[v[i]] = {i, -1};
        else mp[v[i]].s = i;
    }
    build(1, 0, 2*n-1);

    for(int i = 1; i <= n; i++) cout << query(1, 0, 2*n-1, mp[i].f+1, mp[i].s-1).f << " ";
    cout << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
