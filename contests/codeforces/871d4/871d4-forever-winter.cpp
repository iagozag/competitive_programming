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

void solve(){
    int n, m; cin >> n >> m;

    int MAX = 210;
    vector<vi> v(MAX);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;

        v[a].pb(b);
        v[b].pb(a);
    }

    ll x = 0, y = 0;
    for(int i = 0; i < n; i++){
        if(v[i].size() == 1) y = v[v[i][0]].size()-1;
        else{
            bool flag = true;
            for(auto& ve: v[i])
                if(v[ve].size()==1) { flag = false; break; } 
            if(!flag) continue;

            x = v[i].size();
        }

        if(x && y) break;
    }

    cout << x << " " << y << endl; 
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
