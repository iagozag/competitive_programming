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

vi id, sz;

int find(int x){
    return (id[x] == x ? x : find(id[x]));
}

void unio(int p, int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q, sz[q] += sz[q];
}

void cut(int p, int q){
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = p, sz[q] -= sz[p];
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    id = vi(n), sz = vi(n); iota(all(id),0);
    for(int i = 0; i < m; i++) { 
        int a, b; cin >> a >> b; a--, b--; 
        unio(a, b);
    }

    for(int i = 0; i < k; i++){
        string st; int a, b; cin >> st >> a >> b; a--, b--;
        if(st == "ask") { cout << (find(a) == find(b) ? "YES\n" : "NO\n"); }
        else cut(a, b); 
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
