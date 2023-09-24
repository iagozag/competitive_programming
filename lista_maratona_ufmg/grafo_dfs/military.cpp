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

int MAX = 2*1e5+10;
vector<vi> v(MAX);
vector<bool> vis(MAX);

void dfs(int x){

}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i < n; i++){
        int a; cin >> a; a--;
        v[i].pb(a);
        v[a].pb(i);
    }

    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for(auto& x: v[i]) cout << x << " ";
        cout << endl;
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
