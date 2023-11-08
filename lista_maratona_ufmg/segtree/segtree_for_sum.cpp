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

vl a, t;

void build(int node, int tl, int tr){
    if(tl == tr){
        t[node] = a[tl];
        return;
    }
    
    int tm = (tl+tr)>>1;
    build(node*2+1, tl, tm);
    build(node*2+2, tm+1, tr);
    t[node] = t[node*2+1] + t[node*2+2];
}

void update(int node, int tl, int tr, int idx, ll num){
    if(tl == tr){
        t[node] = num;
        return;
    }
    int tm = (tl+tr)>>1;
    if(tl <= idx && idx <= tm) update(node*2+1, tl, tm, idx, num);
    else update(node*2+2, tm+1, tr, idx, num);

    t[node] = t[node*2+1] + t[node*2+2];
}

unsigned long long query(int node, int tl, int tr, int l, int r){
    if(r < tl || l > tr) return 0;
    if(l <= tl && r >= tr) return t[node];

    int tm = (tl+tr)>>1;
    return query(node*2+1, tl, tm, l, r) + query(node*2+2, tm+1, tr, l, r);
}

void solve(){
    int n, m; cin >> n >> m;
    a = vl(n), t = vl(4*n);
    for(auto& x: a) cin >> x;

    build(0, 0, n-1);

    for(int i = 0; i < m; i++){
        ll op, a, b; cin >> op;
        if(op == 1){
            cin >> a >> b;
            update(0, 0, n-1, a, b);
        }
        else{
            cin >> a >> b;
            cout << query(0, 0, n-1, a, b-1) << endl;
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

