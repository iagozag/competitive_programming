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

const int MAX = 5e5+10;
vi seg(4*MAX), lz(4*MAX);

void build(int p, int tl, int tr){
    seg[p] = 0, lz[p] = 0;
    if(tl != tr){
        int tm = (tl+tr)>>1;
        build(p*2, tl, tm), build(p*2+1, tm+1, tr);
    }
}

int update(int p, int tl, int tr, int idx, int val){
    if(idx < tl || idx > tr) return seg[p];
    if(tl == tr) return seg[p] = val;

    int mid = (tl+tr)>>1;
    return seg[p] = update(p*2+1, tl, mid, idx, val) + update(p*2+2, mid+1, tr, idx, val);
}

int query(int p, int tl, int tr, int a, int b){
    if(b < tl || a > tr) return 0;
    if(a <= tl && b >= tr) return seg[p];

    int mid = (tl+tr)>>1;
    return query(p*2+1, tl, mid, a, b) + query(p*2+2, mid+1, tr, a, b);
}

void solve(){
    int n, sz = 1; cin >> n;
    vector<ii> v;
    for(int i = 0; i < n; i++){
        int op, a, sum; cin >> op;
        if(op == 1){
            cin >> a; sz++;
        } else{
            cin >> a >> sum; a--;
            v.pb({a, sum});
        }
    }

    seg = vi(4*sz);
    for(auto& [a, b]: v) update(0, 0, n-1, a, b);
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
