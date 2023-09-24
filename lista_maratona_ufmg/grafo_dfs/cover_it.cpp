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

int MAX = 2e5+10;
vector<vi> v(MAX);
vector<bool> vis(MAX);
vector<bool> cover(MAX, 1);

void dfs(int x){
    vis[x] = true;

    for(auto& ve: v[x]) if(!vis[ve]){

    }
}

void solve(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a-, b--;
        v[a].pb(b);
        v[b].pb(a);
    }

    if(n == 2 && m == 1) { cout << 1 << endl << v[0][0] << endl; return; }

    dfs(0);

    for(int i = 0; i < n; i++){
        if(cover[i]) cout << 
    }
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
