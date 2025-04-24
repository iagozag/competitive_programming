#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void make(vector<ll> &v, vector<ll> &sp) {
    sp[0] = 0;
    for(ll i=1;i<sp.size();i++) sp[i] = sp[i-1]+v[i-1];
}

int32_t main() { _
    int n,q;
    cin >> n >> q;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    set<ll> p;
    for(ll i=1;i<30;i++) p.insert(1LL<<i);

    vector<ll> pot(n,0), imp(n,0), um(n,0);
    for(int i=0;i<n;i++) {
        if(p.count(v[i])) pot[i] = v[i];
        else if((v[i]&1) and v[i]>1) imp[i] = v[i];
        else if(v[i]==1) um[i] = v[i];
    }

    vector<ll> spp(n+1), spi(n+1), spu(n+1);
    make(pot,spp);
    make(imp,spi);
    make(um,spu);

    while(q--) {
        ll l,r;
        cin >> l >> r;
        ll ag = spp[r]-spp[l-1];
        ll br = spi[r]-spi[l-1];
        if((spu[r]-spu[l-1])&1) ag++;
        if(ag>br) cout << "A\n";
        else if(ag==br) cout << "E\n";
        else cout << "B\n";
    }
    
}