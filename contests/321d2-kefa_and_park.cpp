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

ll n, m, MAX = 1e5+10;
ll ans = 0;
vector<vi> v(MAX);
vector<bool> vis(MAX);
vi cats(MAX);
vi qnt_cats(MAX);

void complete_vis(int x){
    vis[x] = true;
    
    for(auto& ve: v[x]) if(!vis[ve]){
        complete_vis(ve);   
    }
}

void dfs(int x, int prev){
    vis[x] = true;

    if(prev != -1){
        if(cats[x]) qnt_cats[x] = qnt_cats[prev]+1;
        else qnt_cats[x] = 0;
    }

    if(qnt_cats[x] > m) { complete_vis(x); return; }
    if(x != 0 && v[x].size() == 1 && qnt_cats[x] <= m) ans++;

    // for(int i = 0; i < n; i++) cout << qnt_cats[i] << " ";
    // cout << "  v: " << x+1 << " ans: " << ans << endl;

    for(auto& ve: v[x]) if(!vis[ve]){
        dfs(ve, x);
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> cats[i];
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--, b--;

        v[a].pb(b);
        v[b].pb(a);
    }

    if(cats[0]) qnt_cats[0] = 1;
    for(int i = 0; i < n; i++) if(!vis[i]){
        dfs(i, -1);
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
