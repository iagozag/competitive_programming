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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 1e3+10, MOD = 1e9+7;

vector<vector<ii>> g;
vi dist;

bool in(int px, int py, int l, int d, int r, int u){
    return(px >= l and px <= r and py >= d and py <= u);
}

int dist_r(int a[4], int b[4]){
    int lxa = a[0], lya = a[1], rxa = a[2], rya = a[3], 
        lxb = b[0], lyb = b[1], rxb = b[2], ryb = b[3];

    if(in(lxa, lya, lxb, lyb, rxb, ryb)) return 0;
    if(in(lxa, rya, lxb, lyb, rxb, ryb)) return 0;
    if(in(rxa, lya, lxb, lyb, rxb, ryb)) return 0;
    if(in(rxa, rya, lxb, lyb, rxb, ryb)) return 0;

    if(rya < lyb){
        if(lxa > rxb) return lxa-rxb+lyb-rya;
        else if(lxb > rxa) return lxb-rxa+lyb-rya;
        return lyb-rya;
    }
    if(lya > ryb){
        if(rxa < lxb) return lxb-rxa+lya-ryb;
        else if(rxb < lxa) return lxa-rxb+lya-ryb;
        return lya-ryb;
    }

    if(rxa < lxb) return lxb-rxa;
    return lxa-rxb;
}

void dijkstra(int s){
    priority_queue<ii> pq; pq.push({0, s});
    while(!pq.empty()){
        auto [w, v] = pq.top(); w -= 2*w; pq.pop();
        if(w >= dist[v]) continue;
        dist[v] = w;
        if(v == 1) break;
        for(auto [ve, d]: g[v]) if(w+d < dist[ve]) pq.push({-w-d, ve});
    }
}

void solve(){
    int sx, sy, dx, dy, n; scanf("%d%d%d%d%d", &sx, &sy, &dx, &dy, &n); n += 2;
    vector<int[4]> robots(n); g = vector<vector<ii>>(n);
    robots[0][0] = sx, robots[0][1] = sy, robots[0][2] = sx, robots[0][3] = sy;
    robots[1][0] = dx, robots[1][1] = dy, robots[1][2] = dx, robots[1][3] = dy;
    rep(i, 2, n){ 
        int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d); 
        robots[i][0] = a, robots[i][1] = b, robots[i][2] = c, robots[i][3] = d;
    }

    rep(i, 0, n) rep(j, i+1, n){
        int dd = dist_r(robots[i], robots[j]);
        g[i].eb(j, dd), g[j].eb(i, dd);
    }

    dist = vi(n, INF);
    dijkstra(0);
    printf("%d\n", dist[1]);
}

int main(){ // _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}

