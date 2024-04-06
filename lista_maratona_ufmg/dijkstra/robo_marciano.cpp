#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
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

const int MAX = 1e3+5;

vector<vector<pair<ll, int>>> g(MAX);
vl dist(MAX, LINF);

ll dist_r(ll lxa, ll lya, ll rxa, ll rya, ll lxb, ll lyb, ll rxb, ll ryb){
    ll ans = LINF;

    if(rya < lyb){
        if(lxa > rxb) ans = lxa-rxb+lyb-rya;
        else if(lxb > rxa) ans = lxb-rxa+lyb-rya;
        else ans = lyb-rya;
    }
    else if(lya > ryb){
        if(rxa < lxb) ans = lxb-rxa+lya-ryb;
        else if(rxb < lxa) ans = lxa-rxb+lya-ryb;
        else ans = lya-ryb;
    }
    else if(rxa < lxb) ans = lxb-rxa;
    else ans = lxa-rxb;

    return max(ans, 0LL);
}

void dijkstra(){
    priority_queue<pair<ll,int>> pq; pq.push({0, 0});
    while(!pq.empty()){
        auto [w, v] = pq.top(); w *= -1; pq.pop();
        if(v == 1) break;
        for(auto [ve, d]: g[v]) if(w+d < dist[ve])
            dist[ve] = w+d, pq.push({-w-d, ve});
    }
}

void solve(){
    ll sx, sy, dx, dy; int n; cin >> sx >> sy >> dx >> dy >> n; n += 2;

    vector<ll[4]> robots(n);
    robots[0][0] = sx, robots[0][1] = sy, robots[0][2] = sx, robots[0][3] = sy;
    robots[1][0] = dx, robots[1][1] = dy, robots[1][2] = dx, robots[1][3] = dy;

    rep(i, 2, n){ 
        ll a, b, c, d; cin >> a >> b >> c >> d; 
        robots[i][0] = a, robots[i][1] = b, robots[i][2] = c, robots[i][3] = d;
    }

    rep(i, 0, n) rep(j, i+1, n){
        ll dd = dist_r(robots[i][0], robots[i][1], robots[i][2], robots[i][3], 
                       robots[j][0], robots[j][1], robots[j][2], robots[j][3]);
        g[i].eb(j, dd), g[j].eb(i, dd);
    }

    dijkstra();
    cout << dist[1] << endl; 
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}

