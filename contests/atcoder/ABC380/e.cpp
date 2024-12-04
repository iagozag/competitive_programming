#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

struct dsu{
	vector<int> id, color, qnt, l, r;

	dsu(int n): id(n), color(n), qnt(n, 1), l(n), r(n) { 
		iota(id.begin(), id.end(), 0), iota(color.begin(), color.end(), 0); 
		iota(l.begin(), l.end(), 0), iota(r.begin(), r.end(), 0); 
	}

	int sz(int a){
		a = find(a);
		return r[a]-l[a]+1;
	}

	int find(int a){ return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(l[a] > l[b]) swap(a, b);
		r[a] = r[b], id[b] = a;
	}

	void coloring(int a, int c){
		a = find(a);
		if(color[a] == c) return;

		qnt[color[a]] -= sz(a);
		color[a] = c;
		qnt[c] += sz(a);
	}

	int get_color(int a){
		a = find(a);
		return color[a];
	}

	int get_l(int a){
		return l[a];
	}

	int get_r(int a){
		return r[a];
	}

	int get_qnt(int c){
		return qnt[c];
	}
};

void solve(){
	int n, Q; cin >> n >> Q;
	dsu D(n);
	for(int i = 0; i < Q; i++){
		int op, a, b; cin >> op >> a; --a;
		if(op == 1){
			cin >> b; --b; a = D.find(a);
			D.coloring(a, b);
			if(D.get_l(a) and D.get_color(D.get_l(a)-1) == b) D.unite(D.get_l(a)-1, a);
			if(D.get_r(a)+1 < n and D.get_color(D.get_r(a)+1) == b) D.unite(a, D.get_r(a)+1);
		} 
		else cout << D.get_qnt(a) << endl;
	}
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
