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

vector<vi> v(110);
vi dist(110, -1);

void dfs(int x){
    for(auto& ve: v[x]) if(dist[ve] == -1){
        dist[ve] = dist[x]+1;
        dfs(ve);
    }
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        v[a].pb(b), v[b].pb(a);
    } 

    dist[0]= 0;
    dfs(0);

    int max= -1, pos = -1;
    for(int i = 0; i < n; i++){
        if(max < dist[i]) max = dist[i], pos = i;
    }

    dist = vi(100, -1); dist[pos] = 0;
    dfs(pos);

    max= -1;
    for(int i = 0; i < n; i++)
        if(max < dist[i]) max = dist[i];


    cout << (max <= 6 ? "S\n" : "N\n"); 
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

