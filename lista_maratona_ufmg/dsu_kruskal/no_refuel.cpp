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

void unio(int p, int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q, sz[q] += sz[p];
}

void solve(){
    int n, k; cin >> n >> k;
    id = vi(n), sz = vi(n, 1); iota(all(id),0);
    vector<tuple<int,int,int>> g;
    for(int i = 0; i < k; i++){
        int a, b, w; cin >> a >> b >> w; a--, b--;
        g.push_back({w, a, b});
    }
    sort(all(g));

    ll max = 0;
    for(auto [w, a, b]: g){
        if(find(a) != find(b)){ unio(a, b); max = w; }
    }

    cout << max << endl; 
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

