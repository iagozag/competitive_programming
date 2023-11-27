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

class Matrix{
    public:
        int m[2][2];

        Matrix(){
            m[0][0] = 1, m[0][1] = 0, m[1][0] = 0, m[1][1] = 1;
        }

        Matrix(int a, int b, int c, int d){
            m[0][0] = a, m[0][1] = b, m[1][0] = c, m[1][1] = d;
        }
};

int r, MAX = 2e5+10;
vector<Matrix> v(MAX); vector<Matrix> seg(4*MAX);

Matrix multiply(Matrix m1, Matrix m2){
    Matrix ans(0,0,0,0);

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                ans.m[i][j] = (ans.m[i][j] + ((m1.m[i][k] * m2.m[k][j]) % r)) % r;

    return ans;
}

Matrix build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = v[tl];

    int tm = (tl+tr)>>1;
    return seg[node] = multiply(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

Matrix query(int node, int tl, int tr, int a, int b){
    if(b < tl || a > tr) return Matrix(1,0,0,1);
    if(a <= tl && b >= tr) return seg[node];

    int tm = (tl+tr)>>1;
    return multiply(query(node*2, tl, tm, a, b), query(node*2+1, tm+1, tr, a, b));
}

void solve(){
    int n, m; cin >> r >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> v[i].m[0][0] >> v[i].m[0][1] >> v[i].m[1][0] >> v[i].m[1][1];

    build(1, 0, n-1);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        Matrix ans = query(1, 0, n-1, a, b);

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++) cout << ans.m[i][j] << " ";
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


