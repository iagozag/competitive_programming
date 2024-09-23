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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m, d;
vector<vi> g;
vi dist;

int bfs(int s){
    dist = vi(n, INF); int ma = 0;
    queue<int> q; q.push(s); dist[s] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        forr(ve, g[v]){
            if(dist[v]+1 < dist[ve]) dist[ve] = dist[v]+1, ma = max(ma, dist[ve]), q.push(ve);
        }
    }

    return ma;
}

void solve(){
    cin >> n >> m >> d;
    g = vector<vi>(n);

    rep(i, 0, m){
        int a, b; cin >> a >> b; --a, --b;
        g[a].eb(b), g[b].eb(a);
    }

    int idx = 0;
    rep(i, 1, n) if(sz(g[i]) < sz(g[idx])) idx = i;

    int dd = bfs(idx), idx2;
    rep(i, 0, n) if(dist[i] == dd){ idx2 = i; break; }

    dd = bfs(idx2);
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
