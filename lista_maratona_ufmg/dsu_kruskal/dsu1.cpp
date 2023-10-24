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

void unio(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] > sz[b]) swap(a,b);
    id[a] = b, sz[b] += a;
}

void solve(){
    int n, m; cin >> n >> m;
    id = vi(n); iota(all(id),0);
    sz = vi(n,1);
    for(int i = 0; i < m; i++){
	    string st; int a, b; cin >> st >> a >> b; a--, b--;
	    if(st == "union") unio(a,b);
	    else cout << (find(a) == find(b) ? "YES\n" : "NO\n");
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
