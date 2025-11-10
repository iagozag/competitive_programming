#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll

const int LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vector<vector<pair<int, int>>> g;
vector<vector<pair<int, int>>> pos;
vector<int> c, c2, dist, dist2, qnt, ans;
vector<vector<pair<int, int>>> qu;

namespace rb{
	stack<pair<int&, int>> st;

	void save(int &x) { st.emplace(x, x); }

	void rollback(int cnt){
		for(int i = 0; i < cnt; i++){
			auto [a, b] = st.top(); st.pop();
			a = b;
		}
	}
};

void dfs(int v, int p){
	if(g[v].size() == 1){
		pos[v].emplace_back(0, v);
	}

	for(auto [ve, w]: g[v]) if(ve != p){
		dfs(ve, v);
		pos[v].emplace_back(dist[ve]+w, c[ve]);
	}

	sort(pos[v].begin(), pos[v].end());

	dist[v] = pos[v][0].first;  
	c[v] = pos[v][0].second;
	qnt[c[v]]++;

	if(pos[v].size() > 1){
		dist2[v] = pos[v][1].first;  
		c2[v] = pos[v][1].second;
	}
}

void reroot(int v, int p, int w){
	if(v and (dist2[v] > dist[p]+w or (dist2[v] == dist[p]+w and c[p] < c2[v]))){
		dist2[v] = dist[p]+w;
		c2[v] = c[p];
	}

	for(auto [ve, ww]: g[v]) if(ve != p)
		reroot(ve, v, ww);
}

void dfs2(int v, int p){
	for(auto [a, b]: qu[v]) ans[b] = qnt[a];

	for(auto [ve, w]: g[v]) if(ve != p){
		if(c[v] != c[ve]){
			if(dist[v]+w < dist[ve] or (dist[v]+w == dist[ve] and c[v] < c[ve])){
				rb::save(qnt[c[ve]]);
				qnt[c[ve]]--;

				rb::save(dist[ve]);
				dist[ve] = dist[v]+w;

				rb::save(c[ve]);
				c[ve] = c[v];

				rb::save(qnt[c[ve]]);
				qnt[c[ve]]++;

				dfs2(ve, v);

				rb::rollback(4);
			} 
			else dfs2(ve, v);
		}
		else{
			rb::save(qnt[c[v]]);
			qnt[c[v]]--;

			rb::save(c[v]);
			c[v] = c2[v];

			rb::save(qnt[c[v]]);
			qnt[c[v]]++;

			rb::save(dist[v]);
			dist[v] = dist2[v];

			dfs2(ve, v);

			rb::rollback(4);
		}
	}
}

int32_t main(){
	cin >> n;
	g = pos = vector<vector<pair<int, int>>>(n); 
	c = c2 = vector<int>(n, LINF); 
	qnt = vector<int>(n); 
	dist = dist2 = vector<int>(n, LINF);
	for(int i = 0; i < n-1; i++){
		int a, b, w; cin >> a >> b >> w; --a, --b;
		g[a].emplace_back(b, w), g[b].emplace_back(a, w);
	}

	int q; cin >> q;
	ans = vector<int>(q);
	qu = vector<vector<pair<int, int>>>(n);
	for(int i = 0; i < q; i++){ int a, b; cin >> a >> b; --a, --b; qu[b].emplace_back(a, i); }

	dfs(0, 0);
	reroot(0, 0, 0);

	dfs2(0, 0);

	for(auto x: ans) cout << x << endl;

	exit(0);
}
