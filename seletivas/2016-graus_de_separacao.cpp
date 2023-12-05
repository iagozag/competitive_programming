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

vi id, rk;

int find(int x){
    return (id[x] == x ? x : find(id[x]));
}

void unio(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(rk[a] > rk[b]) swap(a, b);
    id[a] = b, rk[b] += (rk[a] == rk[b] ? 1 : 0);
}

void solve(){
    int n, m; cin >> n >> m;
    id = vi(n), rk = vi(n, 0); iota(all(id), 0);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        unio(a, b); 
    }

    cout << rk[find(0)] << endl;
    cout << (rk[find(0)] > 6 ? "N\n" : "S\n"); 
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

