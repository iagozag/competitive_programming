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

int MAX = 2*1e4+10, ans;
vector<vi> v(MAX);
vi dist(MAX, -1);

void complete_radial(int x){
    for(auto& ve: v[x]){ 
        if(v[ve].size() < 3 && dist[ve] != -2){
            dist[ve] = -2;
            complete_radial(ve);
        }
    }
}

void dfs(int x){
    for(auto& ve: v[x]){
        if(v[ve].size() == 1) complete_radial(ve);
        else if(dist[ve] == -1){
            dist[ve] = dist[x]+1;
            dfs(ve);
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b; a--, b--;

        v[a].pb(b);
        v[b].pb(a);
    }

    dist[0] = -2;
    complete_radial(0);

    for(int i = 1; i < n; ++i) if(dist[i] == -1){
        dist[i] = 1;
        dfs(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) if(dist[i] >= 1) ans++;

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    return(0);
}
