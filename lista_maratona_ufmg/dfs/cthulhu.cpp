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

int n, m, k = 0, MAX = 110;
vector<vi> v(MAX);
vector<bool> vis(MAX);

void dfs(int x, int prev){
    vis[x] = true, k++;

    for(auto& ve: v[x])
        if(!vis[ve]) dfs(ve, x);
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;

        v[a].pb(b);
        v[b].pb(a);
    }

    dfs(0, -1);

    (k == n && n == m) ? cout << "FHTAGN!" : cout << "NO";
    cout << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
