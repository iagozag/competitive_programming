#include <bits/stdc++.h>
using namespace std;

#define _ ios_sync:stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int MAX = 2e5+10, MAX2 = 20;

vector<vector<int>> g(MAX);
int n, p;
int pai[MAX2][MAX];
int in[MAX], out[MAX];
int d[MAX];
vector<int> v(MAX);

void dfs(int k){
    in[k] = p++, d[k] += v[k];
    for(int i = 0; i < (int)g[k].size(); i++){
        if(in[g[k][i]] == -1) 
            d[g[k][i]] += d[k], pai[0][g[k][i]] = k, dfs(g[k][i]);
    }
    out[k] = p++;
}

void build(int raiz){
    for(int i = 0; i < n; i++) pai[0][i] = i;
    p = 0, memset(in, -1, sizeof in);
    dfs(raiz);

    for(int k = 1; k < MAX2; k++) for(int i = 0; i < n; i++)
        pai[k][i] = pai[k-1][pai[k-1][i]];
}

bool anc(int a, int b){ return in[a] <= in[b] and out[a] >= out[b]; }

int lca(int a, int b){
    if(anc(a, b)) return a;
    if(anc(b, a)) return b;

    for(int k = MAX2-1; k >= 0; k--)
        if(!anc(pai[k][a], b)) a = pai[k][a];

    return pai[0][a];
}

int dist(int a, int b){ 
    int ans = d[a]+d[b], l = lca(a, b);

    if(l == 0) ans -= d[0];
    else ans -= d[l], l = pai[0][l], ans -= d[l];

    return ans; 
}


int32_t main(){
    int q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i < n; i++){ int pp; cin >> pp; --pp; g[pp].emplace_back(i), g[i].emplace_back(pp); }

    build(0);

    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b; --a, --b;
        cout << dist(a, b) << endl;
    }

    exit(0);
}