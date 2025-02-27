#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<vector<int>> v, dist, vis, cnt, pref;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void printt(vector<vector<int>> mat){
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cout << mat[i][j] << " \n"[j==m-1];
	cout << endl;
}

void bfs(){
	dist = vector<vector<int>>(n, vector<int>(m, INF));
	vis = vector<vector<int>>(n, vector<int>(m));

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
	cout << mid << endl;
	int need = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		if(dist[i][j] > mid) cnt[i][j] = 1, need++;
		else cnt[i][j] = 0;
	}

	printt(cnt);

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) 
		pref[i][j] = (i ? pref[i-1][j] : 0) + (j ? pref[i][j-1] : 0) - (i and j ? pref[i-1][j-1] : 0) + cnt[i][j];

	printt(pref);

	auto get_sum = [&](int a, int b, int c, int d) -> int{
		return pref[c][d] - (a ? pref[a-1][d] : 0) - (b ? pref[c][b-1] : 0) + (a and b ? pref[a-1][b-1] : 0);
	};

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		int a = max(0LL, i-mid), b = max(0LL, j-mid), c = min(n-1, i+mid), d = min(m-1, j+mid);
		if(get_sum(a, b, c, d) == need) return {true, i, j};
	}

	return {false, -1, -1};
}

void solve(){
	cin >> n >> m;
	v = dist = cnt = pref = vector<vector<int>>(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < m; j++) v[i][j] = (s[j] == '#');
	}

	bfs();

	printt(dist);

	int l = 0, r = n*m, ans = r, cx = -1, cy = -1;
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
