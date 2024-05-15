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

int n;
vector<string> v;
vector<vi> dist;

vector<pii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool val(int i, int j){
    return i >= 0 and i < n and j >= 0 and j < n and dist[i][j] == INF;
}

ll bfs(pii s, pii d, char c){
    dist = vector<vi>(n, vi(n, INF)); 
    dist[s.ff][s.ss] = 0;
    deque<pii> q; q.push_front(s);
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop_front();
        for(auto [i, j]: moves){
            i += x, j += y;
            if(!val(i, j)) continue;

            if(v[i][j] == c and dist[x][y] < dist[i][j]) 
                dist[i][j] = dist[x][y], q.push_front({i, j});
            else if(v[i][j] != c and dist[x][y]+1 < dist[i][j]) 
                dist[i][j] = dist[x][y]+1, q.push_back({i, j});
        }
    }

    return dist[d.ff][d.ss];
}

void solve(){
    cin >> n; v = vector<string>(n); rep(i, 0, n) cin >> v[i];

    cout << bfs({0, 0}, {n-1, n-1}, 'R')+bfs({n-1, 0}, {0, n-1}, 'B') << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
