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

int MAX = 1e5;
vector<vi> v(MAX);
vi dist(MAX, -1);

void dfs(int x){
    for(auto& ve: v[x]) if(dist[ve] == -1){
        dist[ve] = dist[x]+1;
        dfs(ve);
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--, b--;

        v[a].pb(b);
        v[b].pb(a);
    }

    dist[0] = 0;
    dfs(0);

    int max = -1, pos = -1;
    for(int i = 0; i < n; i++) 
        if(max < dist[i]) max = dist[i], pos = i;

    fill(dist.begin(), dist.end(), -1);
    dist[pos] = 0;
    dfs(pos);

    max = -1;
    for(int i = 0; i < n; i++) 
        if(max < dist[i]) max = dist[i];

    cout << max << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
