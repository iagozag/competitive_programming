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

int n;
vi id, sz;
stack<ii> stk;

int find(int x){
    return id[x] = (id[x] == x ? x : find(id[x]));
}

void unio(int p, int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q, sz[q] += sz[p];
}

void cut(int a, int b){
    id = vi(n), sz = vi(n, 1); iota(all(id),0);
    stack<ii> aux;
    while(!stk.empty()){
        ii p = stk.top(); stk.pop();
        if((p.f == a && p.s == b) || (p.f == b && p.s == a)) continue;
        unio(p.f, p.s); aux.push({p.f, p.s});
    }

    stk = aux;
}

void solve(){
    int m, k; cin >> n >> m >> k;
    id = vi(n), sz = vi(n, 1); iota(all(id),0);

    for(int i = 0; i < m; i++) { 
        int a, b; cin >> a >> b; a--, b--; 
        stk.push({a, b}); unio(a, b);
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
