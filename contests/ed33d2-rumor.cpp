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

int MAX = 1e5+10, mini = INF;
vector<vi> v(MAX);
vector<bool> vis(MAX);
vi cost;

void dfs(int x){
    vis[x] = true;
    if(mini > cost[x]) mini = cost[x];

    for(auto& ve: v[x]) if(!vis[ve]){
        dfs(ve);
    }
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a; cin >> a; cost.pb(a);
    }

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        v[a].pb(b); v[b].pb(a);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) if(!vis[i]){
        dfs(i);
        ans += mini, mini = INF;
    }

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
