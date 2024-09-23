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

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int h, w, q; cin >> h >> w >> q;
    vector<set<int>> row(h+1), col(w+1); 
    rep(i, 1, h+1) rep(j, 1, w+1) row[i].insert(j);
    rep(i, 1, w+1) rep(j, 1, h+1) col[i].insert(j);

    rep(i, 0, q){
        int a, b; cin >> a >> b;
        if(row[a].count(b)){ row[a].erase(b), col[b].erase(a); continue; }

        auto itr = row[a].upper_bound(b); 
        if(itr != row[a].end()) col[*itr].erase(a), row[a].erase(*itr);

        auto itl = row[a].lower_bound(b);
        if(itl != row[a].begin()) --itl, col[*itl].erase(a), row[a].erase(*itl);

        auto itd = col[b].upper_bound(a); 
        if(itd != col[b].end()) row[*itd].erase(b), col[b].erase(*itd);

        auto itu = col[b].lower_bound(a);
        if(itu != col[b].begin()) itu--, row[*itu].erase(b), col[b].erase(*itu);
    }

    int ans = 0;
    rep(i, 1, h+1) ans += row[i].size(); 
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
