#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAXN = 5e5+1, MOD = 1e9+7;

vector<int> g[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], dist[MAXN];
int cur_pos;
int seg[4 * MAXN], lazy[4 * MAXN];
int n;

void apply(int node, int start, int end, int value) {
    seg[node] = (end - start + 1) * value;
    lazy[node] = value;
}

void push(int node, int start, int end) {
    if (lazy[node] != -1) {
        int mid = (start + end) / 2;
        apply(2 * node, start, mid, lazy[node]);
        apply(2 * node + 1, mid + 1, end, lazy[node]);
        lazy[node] = -1;
    }
}

void update(int node, int start, int end, int l, int r, int value) {
    if (start > r || end < l) return;
    if (start >= l && end <= r) {
        apply(node, start, end, value);
        return;
    }
    push(node, start, end);
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, value);
    update(2 * node + 1, mid + 1, end, l, r, value);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

int query_sum(int node, int start, int end) {
    if (start == end) return seg[node];
    push(node, start, end);
    int mid = (start + end) / 2;
    return query_sum(2 * node, start, mid) + query_sum(2 * node + 1, mid + 1, end);
}

int dfs(int v) {
    int size = 1, max_size = 0;
    for (int u : g[v]) {
        if (u == parent[v]) continue;
        parent[u] = v;
        depth[u] = depth[v] + 1;
        int subtree_size = dfs(u);
        size += subtree_size;
        if (subtree_size > max_size) {
            max_size = subtree_size;
            heavy[v] = u;
        }
    }
    return size;
}

void decompose(int v, int h) {
    head[v] = h;
    pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h);
    for (int u : g[v]) {
        if (u != parent[v] && u != heavy[v])
            decompose(u, u);
    }
}

void update_path(int u, int v, int value) {
    for (; head[u] != head[v]; v = parent[head[v]]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        update(1, 0, n - 1, pos[head[v]], pos[v], value);
    }
    if (depth[u] > depth[v]) swap(u, v);
    update(1, 0, n - 1, pos[u], pos[v], value);
}

void dfs2(int v, int p){
    if(v != 0) dist[v] = dist[p]+1;
    for(auto ve: g[v]) if(ve != p) dfs2(ve, v);
}

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) g[i].clear();
    fill(parent, parent + n, -1);
    fill(depth, depth + n, 0);
    fill(heavy, heavy + n, -1);
    fill(head, head + n, 0);
    fill(pos, pos + n, 0);
    fill(dist, dist + n, 0);
    fill(seg, seg + 4 * n, 0);
    fill(lazy, lazy + 4 * n, -1);

    for(int i = 0; i < n-1; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }

    parent[0] = -1;
    depth[0] = 0;
    dfs(0);
    cur_pos = 0;
    decompose(0, 0);

    dist[0] = 0;
    dfs2(0, -1);

    vector<vector<int>> mp(n);
    for(int i = 0; i < n; i++){
        mp[dist[i]].emplace_back(i); 
    }

    int ans = INF;
    for(int i = 0; i < n; i++){
        if(mp[i].size() == 0) break;
        for(auto x: mp[i]) update_path(0, x, 1);
        ans = min(ans, n-query_sum(1, 0, n - 1));
        for(auto x: mp[i]) update_path(0, x, 0);
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
