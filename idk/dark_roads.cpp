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
    return id[x] = (id[x] == x ? x : find(id[x]));
}

void uni(int p, int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p,q);
    id[p] = q, sz[q] += p;
}

void solve(){
    while(1){
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0) break;
        vector<tuple<int,int,int>> g(m);        
        id = vi(n); iota(all(id), 0);
        sz = vi(n, 1);
        int cost = 0, cost_max = 0;
        for(int i = 0; i < m; i++){
            int w, a, b; cin >> a >> b >> w;
            g[i] = {w,a,b};
            cost_max += w;
        }
        sort(all(g));

        for(auto [w, a, b]: g){
            if(find(a) != find(b))
                uni(a, b), cost += w;
        }

        cout << cost_max-cost << endl;
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
