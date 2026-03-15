#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+10, MOD = 1e9+7;

struct fence{
	int l, r, x, id, sz;
	fence(int _l, int _r, int _x, int _id, int _sz): l(_l), r(_r), x(_x), id(_id), sz(_sz) {}
};

vector<fence> f;

int find(int x){
	return f[x].id = (f[x].id == x ? x : find(f[x].id));
}

void unio(int a, int b, int x){
	a = find(a), b = find(b);
	if(a == b) return;
	if(f[a].sz < f[b].sz) swap(a, b);
	f[a].l = min(f[a].l, f[b].l), f[a].r = max(f[a].r, f[b].r);
	f[a].x = x, f[b].id = a, f[a].sz += f[b].sz;
}

set<int> lim[MAX];

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		f.emplace_back(i, i, x, i, 1);
		lim[x].insert(i);
	}

	int m; cin >> m;
	for(int i = 0; i < m; i++){
		int x; cin >> x;
		if(lim[x].size() == 0) continue;

		int l = *lim[x].begin(), r = *lim[x].rbegin(), j = l;
		while(j <= r){
			if(lim[f[j].x].size()) lim[f[j].x].erase(j);
			unio(l, j, x);
			int id = find(j);
			j = f[id].r+1;
		}
	}

	for(int i = 0; i < n; i++){
		int x = find(i);
		cout << f[x].x << ' ';
	}

	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
