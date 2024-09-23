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

int n, m, q;
vi pes_pos, pos_pes, age, vis;
vector<vi> g;

int dfs(int v){
    vis[v] = 1;

    int mi = INF;
    forr(ve, g[v]) if(!vis[ve]){
        ckmin(mi, dfs(ve)); 
    }
    return min(age[pos_pes[v]], mi);
}

void solve(){
    cin >> n >> m >> q;
    age.resize(n); forr(x, age) cin >> x;
    g.resize(n); pes_pos = pos_pes = vi(n);
    rep(i, 0, n) pes_pos[i] = pos_pes[i] = i;

    rep(i, 0, m){
        int a, b; cin >> a >> b; --a, --b;
        g[b].eb(a);
    }

    rep(i, 0, q){
        char c; int a, b; cin >> c;
        if(c == 'T'){
            cin >> a >> b; --a, --b;
            swap(pes_pos[a], pes_pos[b]); 
            pos_pes[pes_pos[a]] = a;
            pos_pes[pes_pos[b]] = b;
        }
        else{
            cin >> a; --a;
            if(!g[pes_pos[a]].size()) cout << '*' << endl;
            else{
                vis = vi(n); int mi = INF; vis[pes_pos[a]] = 1;
                forr(ve, g[pes_pos[a]]) ckmin(mi, dfs(ve));
                cout << mi << endl;
            }
        }
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
