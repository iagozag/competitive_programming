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

vi id, sz, children;

int findp(int x){
    return (id[x] == x ? x : findp(id[x]));
}

int findc(int x){
    return children[x] = (children[x] == x ? x : findc(children[x]));
}

void unio(int a, int b){
    a = findp(a), b = findp(b);
    if(sz[a] < sz[b]) swap(a, b);
    id[a] = findc(b), sz[b] += sz[a];
    children[findc(b)] = a; 
}

void solve(){
    int n; cin >> n;
    id = vi(n), sz = vi(n,1), children = vi(n); iota(all(id), 0); iota(all(children), 0);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--, b--;
        unio(a, b);
    }

    int p = findc(0);
    while(id[p] != p) { cout << p+1 << " "; p = id[p]; }
    cout << p+1 << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

