#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const ll MAX = pow(2, 20)+10;

void solve(){
    int n, m; cin >> n >> m; int MAXL = pow(2, m);
    vector<vi> g(MAXL); vi dist(MAXL, INF);

    string mtx[n]; rep(i, 0, n) cin >> mtx[i];

    rep(i, 0, MAXL){
        string a = bitset<20>(i).to_string();
        repr(j, 19, 20-m){
            string tmp = a; tmp[j] = (tmp[j] == '1' ? '0' : '1');
            int b = bitset<20>(tmp).to_ulong(); 
            g[i].eb(b);
        }
    }

    queue<int> q;
    rep(i, 0, n){ int x = bitset<20>(mtx[i]).to_ulong(); dist[x] = 0, q.push(x); }

    while(!q.empty()){
        int v = q.front(); q.pop();
        forr(ve, g[v]) if(dist[v]+1 < dist[ve]) dist[ve] = dist[v]+1, q.push(ve);
    }  

    int ma = 0;
    rep(i, 1, MAXL) if(dist[i] > dist[ma]) ma = i;

    cout << bitset<20>(ma).to_string().substr(20-m) << endl; 
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
