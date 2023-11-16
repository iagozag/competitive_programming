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

int r, MAX = 2e5+10;
vector<vector<vi>> v(MAX, vector<vi>(2, vi(2))); vector<vector<vi>> seg(4*MAX, vector<vi>(2, vi(2)));

vector<vi> multiply(vector<vi> m1, vector<vi> m2){
    vector<vi> ans(2, vi(2));

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                ans[i][j] = (ans[i][j] + ((m1[i][k] * m2[k][j]) % r)) % r;

    return ans;
}

vector<vi> build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = v[tl];

    int tm = (tl+tr)>>1;
    return seg[node] = multiply(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

vector<vi> query(int node, int tl, int tr, int a, int b){
    if(b < tl || a > tr) return {{1, 0}, {0, 1}};
    if(a <= tl && b >= tr) return seg[node];

    int tm = (tl+tr)>>1;
    return multiply(query(node*2, tl, tm, a, b), query(node*2+1, tm+1, tr, a, b));
}

void solve(){
    int n, m; cin >> r >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> v[i][0][0] >> v[i][0][1] >> v[i][1][0] >> v[i][1][1];

    build(1, 0, n-1);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        vector<vi> ans = query(1, 0, n-1, a, b);

        for(auto& x: ans){
            for(auto& y: x) cout << y << " ";
            cout << endl;
        }
        cout << endl;
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}


