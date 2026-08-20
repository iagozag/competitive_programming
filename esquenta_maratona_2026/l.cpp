#include <bits/stdc++.h>
using namespace std;

#define _ ios_sync:stdin(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;
const ll INF = 1e18;

const int MAX = 2e5+10;
vector<ll> seg(4*MAX), lz(4*MAX);

void prop(int p, int l, int r) {
    seg[p] += lz[p];
    if(l != r) lz[2*p]+= lz[p], lz[2*p+1] += lz[p];
    lz[p] = 0;
}

int update(int p, int l, int r, int a, int b, int x) {
    prop(p, l, r);
    if(a <= l and r <= b) {
        lz[p] += x;
        prop(p, l, r);
        return seg[p];
    }
    if(r < a or l > b) return seg[p]; 
    int m = (l+r)/2;
    return seg[p] = max(update(p*2, l, m, a, b, x), update(p*2+1, m+1, r, a, b, x));
}

int query(int p, int l, int r, int a, int b) {
    prop(p, l, r);

    if(a <= l and b >= r) return seg[p];
    if(r < a or l > b) return -INF;
    int m = (l+r)/2;

    return max(query(p*2, l, m, a, b), query(p*2+1, m+1, r, a, b));
}


int32_t main(){ 
    int n, q; cin >> n >> q;

    while(q --) {
        int t; cin >> t;
        if(t == 1) {
            int l, r, x; cin >> l >> r >> x;
            l --, r--;
            update(1, 0, n-1, l, r, x);
        } else {
            int l, r; cin >> l >> r; l --, r--;
            cout << query(1, 0, n-1, l, r) << endl;
        }
    }
}