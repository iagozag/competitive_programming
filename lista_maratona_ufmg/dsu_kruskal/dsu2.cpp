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

vi id, sz, mi, ma;

int find(int x){
    return id[x] = (id[x] == x ? x : find(id[x]));
}

void unio(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] > sz[b]) swap(a,b);
    mi[b] = min(mi[a], mi[b]), ma[b] = max(ma[a], ma[b]);
    id[a] = b, sz[b] += sz[a];
}

void solve(){
    int n, m; cin >> n >> m;
    id = vi(n);
    sz = vi(n,1); mi = vi(n); ma = vi(n);
    iota(all(id), 0); iota(all(mi), 0); iota(all(ma), 0);

    for(int i = 0; i < m; i++){
	    string st; int a, b; cin >> st;
	    if(st == "union") cin >> a >> b, a--, b--, unio(a,b);
	    else{
            cin >> a; a--; a = find(a);
            cout << mi[a]+1 << " " << ma[a]+1 << " " << sz[a] << endl;
        }
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

