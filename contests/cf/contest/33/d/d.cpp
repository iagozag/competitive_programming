#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

const double EPS = 1e-12;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

struct pt {
	double x, y;
	pt(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
	pt operator + (const pt& p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt& p) const { return pt(x-p.x, y-p.y); }
	pt operator * (double c) const { return pt(x*c, y*c); }
	pt operator / (double c) const { return pt(x/c, y/c); }
};

double dot(pt p, pt q) { return p.x*q.x+p.y*q.y; }
double cross(pt p, pt q) { return p.x*q.y-p.y*q.x; }
double dt(pt p, pt q) { return sqrt(dot(p-q, p-q)); }

pt center(pt p, pt q, pt r) {
	pt a = p-r, b = q-r;
	pt c = pt(dot(a, p+r)/2, dot(b, q+r)/2);
	return pt(cross(c, pt(a.y, b.y)), cross(pt(a.x, b.x), c)) / cross(a, b);
}

struct circle {
	pt cen;
	double r;
	circle(pt cen_, double r_) : cen(cen_), r(r_) {}
	circle(pt a, pt b, pt c) {
		cen = center(a, b, c);
		r = dt(cen, a);
	}
	bool inside(pt p) { return dt(p, cen) < r+EPS; }
};

vector<int> par, dist, id;

int dfs(int v){
	if(dist[v] != -1) return dist[v];
	dist[v] = dfs(par[v])+1;
	return dist[v];
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<pt> ctrl; 
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		ctrl.emplace_back(x, y);
	}
	vector<circle> reg; 
	for(int i = 0; i < m; i++){
		int r, x, y; cin >> r >> x >> y;
		reg.emplace_back(pt(x, y), r);
	}

	par = vector<int>(m+1), dist = vector<int>(m+1, -1), id = vector<int>(n);
	for(int i = 0; i < m; i++){
		int idx = -1;
		for(int j = 0; j < m; j++)
			if(i != j and reg[j].inside(reg[i].cen) and reg[j].r > reg[i].r and (idx == -1 or reg[j].r < reg[idx].r)) 
				idx = j;

		par[i+1] = idx+1;
	}

	for(int i = 0; i < n; i++){
		int idx = -1;
		for(int j = 0; j < m; j++)
			if(reg[j].inside(ctrl[i]) and (idx == -1 or reg[j].r < reg[idx].r)) 
				idx = j;

		id[i] = idx+1;
	}

	dist[0] = 0;
	for(int i = 0; i < m+1; i++) dfs(i);

	int LOG = 0; while((1<<LOG) <= m+1) LOG++;

	vector<vector<int>> dp(m+1, vector<int>(LOG));
	for(int i = 0; i < m+1; i++) dp[i][0] = par[i];
	for(int p = 1; p < LOG; p++) for(int v = 0; v < m+1; v++) dp[v][p] = dp[dp[v][p-1]][p-1];

	for(int i = 0; i < k; i++){
		int a, b; cin >> a >> b; --a, --b; a = id[a], b = id[b];
		if(dist[a] > dist[b]) swap(a, b);

		int ans = 0, need = dist[b]-dist[a];
		for(int j = LOG-1; j >= 0; j--) if(need&(1<<j)) ans += (1<<j), b = dp[b][j];

		if(a == b){ cout << ans << endl; continue; }

		for(int j = LOG-1; j >= 0; j--) if(dp[a][j] != dp[b][j]) ans += (1<<(j+1)), a = dp[a][j], b = dp[b][j];
		cout << ans+2 << endl;
	}
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
