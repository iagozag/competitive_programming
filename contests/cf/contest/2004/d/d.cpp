#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, q; cin >> n >> q;
    map<char, int> mpc;
    mpc['B'] = 0, mpc['G'] = 1, mpc['R'] = 2, mpc['Y'] = 3;

    map<int, vi> mp;
    
    vi v(n);
    rep(i, 0, n){
        char c; cin >> c;
        v[i] |= (1<<mpc[c]);
        cin >> c;
        v[i] |= (1<<mpc[c]);

        mp[v[i]].eb(i);
    }

    rep(i, 0, q){
        int a, b; cin >> a >> b; --a, --b;
        if(a > b) swap(a, b);

        if(a == b) cout << 0 << endl;
        else if(v[a]&v[b]) cout << b-a << endl;
        else{
            vi p1, p2;
            rep(j, 0, 4){
                if((1<<j)&v[a]) p1.eb(1<<j);
                if((1<<j)&v[b]) p2.eb(1<<j);
            }

            int mi = INF;
            rep(l, 0, 2) rep(r, 0, 2){
                int need = p1[l]+p2[r];

                auto ub = upper_bound(all(mp[need]), a);
                if(sz(mp[need])){
                    int idxub;
                    if(ub != mp[need].end()){
                        idxub = ub-mp[need].begin();
                        if(mp[need][idxub] < b) mi = b-a;
                        else ckmin(mi, mp[need][idxub]-a+mp[need][idxub]-b);
                        
                    }
                    ub--;
                    if(ub >= mp[need].begin()){
                        idxub = ub-mp[need].begin();
                        ckmin(mi, a-mp[need][idxub]+b-mp[need][idxub]);
                    }
                }
            }

            cout << (mi == INF ? -1 : mi) << endl;
        }
    }
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
