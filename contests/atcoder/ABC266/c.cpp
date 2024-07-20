#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    vector<pii> v(4); rep(i, 0, 4) cin >> v[i].ff >> v[i].ss;
    rep(i, 0, 4){
        int ax = (v[(i+1)%4].ff-v[i].ff), ay = (v[(i+1)%4].ss-v[i].ss),
            bx = (v[(i+2)%4].ff-v[(i+1)%4].ff), by = (v[(i+2)%4].ss-v[(i+1)%4].ss); 
        if(ax*by-ay*bx <= 0) return no();
    }
    return yes();
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
