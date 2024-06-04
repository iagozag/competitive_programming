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

void no(){ cout << "-1" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vi path(int l, int r){
    vi pl, pr;
    while((int)log2(l) > (int)log2(r)) pl.eb(l), l >>= 1;
    while((int)log2(r) > (int)log2(l)) pr.eb(r), r >>= 1;
    while(l != r){
        pl.eb(l), pr.eb(r);
        l >>= 1, r >>= 1;
    }
    pl.eb(l), reverse(all(pr));
    forr(x, pr) pl.eb(x);
    return pl;
}

void solve(){
    int n; cin >> n;
    vi v(n); forr(x, v) cin >> x;
    vi ans = v; int l = -1, r = -1;
    rep(i, 0, n){
        if(v[i] != -1){
            if(l == -1) l = i;
            r = i;
        } 
    }

    if(l == -1){
        rep(i, 0, n) cout << (i&1)+1 << " \n"[i==n-1];
        return;
    }

    repr(i, l-1, 0) ans[i] = (i&1 and (ans[i+1]>>1) > 0) ? ans[i+1]>>1 : ans[i+1]<<1;
    rep(i, r+1, n) ans[i] = (i&1 and (ans[i-1]>>1) > 0) ? ans[i-1]>>1 : ans[i-1]<<1;

    int k = l+1;
    while(k <= r){
        while(v[k] == -1) k++;

        if(k == l+1){
            if(v[l] != v[k]/2 and v[k] != v[l]/2) return no();
            l = k, k++;
            continue;
        }

        if(v[l] == v[k]){
            if(!((k-l+1)&1)) return no();
            rep(i, l+1, k) ans[i] = (i&1 and (ans[i-1]>>1) > 0) ? ans[i-1]>>1 : ans[i-1]<<1;
        } else{
            vi p = path(v[l], v[k]);

            if(sz(p) > k-l+1 or (sz(p)&1) != ((k-l+1)&1)) return no();

            int j = 0;
            rep(i, l, k+1){
                ans[i] = p[j++];
                if(j == sz(p) and i != k) j -= 2;
            }
        }

        l = k, k++;
    }

    forr(x,ans) cout << x << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
