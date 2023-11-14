#include<bits/stdc++.h>
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

int MAX = 1e5+10;
vi a(MAX);
vector<ii> v(4*MAX);

ii combine(ii a, ii b){
    if(a.f < b.f) return a;
    if(a.f > b.f) return b;
    return {a.f, a.s+b.s};
}

ii build(int node, int tl, int tr){
    if(tl == tr) return v[node] = {a[tl], 1};

    int tm = (tl+tr)>>1;
    return v[node] = combine(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

ii update(int node, int tl, int tr, int idx, int val){
    if(idx < tl || idx > tr) return v[node];
    if(tl == tr) return v[node] = {val, 1};

    int tm = (tl+tr)>>1;
    return v[node] = combine(update(node*2, tl, tm, idx, val), update(node*2+1, tm+1, tr, idx, val));
}

ii query(int node, int tl, int tr, int a, int b){
    if(b < tl || a > tr) return {INF, -1};
    if(a <= tl && b >= tr) return v[node];

    int tm = (tl+tr)>>1;
    return combine(query(node*2, tl, tm, a, b), query(node*2+1, tm+1, tr, a, b));
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n-1);

    for(int i = 0; i < m; i++){
        int op, a, b; cin >> op;
        if(op == 1){
            cin >> a >> b;
            update(1, 0, n-1, a, b);
        } else{
            cin >> a >> b;
            auto [x, y] = query(1, 0, n-1, a, b-1);
            cout << x << " " << y << endl;
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
