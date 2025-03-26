#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

const int INF = 0x3f3f3f3f;

int n, m, more;
vector<vector<int>> dist, prefl, prefr;
vector<vector<bool>> v, vis;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(){
	dist = vector<vector<int>>(n, vector<int>(m, INF));
	vis = vector<vector<bool>>(n, vector<bool>(m));

	queue<pair<int, int>> q;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(v[i][j]) q.push({i, j}), dist[i][j] = 0;

	while(!q.empty()){
		auto [a, b] = q.front(); q.pop();
		if(vis[a][b]) continue;
		vis[a][b] = 1;

		for(auto [x, y]: moves){
			x += a, y += b;
			if(x >= 0 and x < n and y >= 0 and y < m and dist[x][y] > dist[a][b]+1)
				dist[x][y] = dist[a][b]+1, q.push({x, y});
		}
	}
}

tuple<bool, int, int> good(int mid){
	auto ok = [&](int i, int j) -> bool{
		return dist[i][j] > mid;
	};

	prefl = prefr = vector<vector<int>>(n, vector<int>(m));

	int need = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		if(i and j) prefr[i][j] = prefr[i-1][j-1];
		if(i and j+1 < m) prefl[i][j] = prefl[i-1][j+1];
		if(ok(i, j)) prefr[i][j]++, prefl[i][j]++, need++;
	}

	auto val = [&](int a, int b){
		return a >= 0 and a < n and b >= 0 and b < m;
	};

	auto get_sum_l = [&](int a, int b, int c, int d) -> int{
		if(a >= n) b += a-(n-1), a = n-1;
		if(b < 0) a += b, b = 0;
		if(c < 0) d += c, c = 0;
		if(d >= m) c += d-(m-1), d = m-1;

		if(!val(a, b) or !val(c, d)) return 0;

		return prefl[a][b]-(c > 0 and d+1 < m ? prefl[c-1][d+1] : 0);
	};

	auto get_sum_r = [&](int a, int b, int c, int d) -> int{
		if(a >= n) b -= a-(n-1), a = n-1;
		if(b >= m) a -= b-(m-1), b = m-1;
		if(c < 0) d -= c, c = 0;
		if(d < 0) c -= d, d = 0;
		
		if(!val(a, b) or !val(c, d)) return 0;

		return prefr[a][b]-(c > 0 and d > 0 ? prefr[c-1][d-1] : 0);
	};

	int first = 0;
	for(int i = 0; i <= min(n-1, mid); i++) for(int j = 0; i+j <= min(m-1, mid); j++) first += ok(i, j);

	for(int i = 0; i < n; i++){
		if(i) first += get_sum_l(i+mid, 0, i, mid), first -= get_sum_r(i-1, mid, i-1-mid, 0);

		if(first == need and !v[i][0]) return {true, i, 0};

		int have = first;
		for(int j = 1; j < m; j++){
			if(j+mid < m) have -= ok(i, j+mid);
			if(j-1-mid >= 0) have += ok(i, j-1-mid);

			have -= get_sum_l(i, j-1-mid, i-mid, j-1);
			have -= get_sum_r(i+mid, j-1, i, j-1-mid);
			have += get_sum_l(i+mid, j, i, j+mid);
			have += get_sum_r(i, j+mid, i-mid, j);
						
			if(have == need and !v[i][j]) return {true, i, j};
		}
	}

	return {false, -1, -1};
}

void solve(){
	cin >> n >> m;
	v = vector<vector<bool>>(n, vector<bool>(m));

	int qnt = 0;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < m; j++) if(s[j] == '#') v[i][j] = 1, qnt++;
	}

	if(!qnt){
		v[n/2][m/2] = 1;
		cout << n/2+m/2 << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) cout << (v[i][j] ? '#' : '.');
			cout << endl;
		}
		return;
	}

	bfs();

	int l = 0, r = n/2+m/2, ans = r, cx = -1, cy = -1;
	while(l <= r){
		int mid = l+(r-l)/2;

		auto [pos, x, y] = good(mid);
		if(pos) ans = mid, cx = x, cy = y, r = mid-1;
		else l = mid+1;
	}

	if(cx != -1) v[cx][cy] = 1;

	cout << ans << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << (v[i][j] ? '#' : '.');
		cout << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
