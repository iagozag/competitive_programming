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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

// SegTree Colorida
//
// Cada posicao tem um valor e uma cor
// O construtor receve um vector de {valor, cor}
// e o numero de cores (as cores devem estar em [0, c-1])
// query(c, a, b) retorna a soma dos valores
// de todo mundo em [a, b] que tem cor c
// update(c, a, b, x) soma x em todo mundo em
// [a, b] que tem cor c
// paint(c1, c2, a, b) faz com que todo mundo
// em [a, b] que tem cor c1 passe a ter cor c2
//
// Complexidades:
// construir - O(n log(n)) espaco e tempo
// query - O(log(n))
// update - O(log(n))
// paint - O(log(n)) amortizado

struct seg_color {
	struct node {
		node *l, *r;
		int cnt;
		ll val, lazy;
		node() : l(NULL), r(NULL), cnt(0), val(0), lazy(0) {}
		void update() {
			cnt = 0, val = 0;
			for (auto i : {l, r}) if (i) {
				i->prop();
				cnt += i->cnt, val += i->val;
			}
		}
		void prop() {
			if (!lazy) return;
			val += lazy*(ll)cnt;
			for (auto i : {l, r}) if (i) i->lazy += lazy;
			lazy = 0;
		}
	};

	int n;
	vector<node*> seg;

	seg_color(vector<pair<int, int>>& v, int c) : n(v.size()), seg(c, NULL) {
		for (int i = 0; i < n; i++)
			seg[v[i].second] = insert(seg[v[i].second], i, v[i].first, 0, n-1);
	}
	~seg_color() {
		queue<node*> q;
		for (auto i : seg) q.push(i);
		while (q.size()) {
			auto i = q.front(); q.pop();
			if (!i) continue;
			q.push(i->l), q.push(i->r);
			delete i;
		}
	}

	node* insert(node* at, int idx, int val, int l, int r) {
		if (!at) at = new node();
		if (l == r) return at->cnt = 1, at->val = val, at;
		int m = (l+r)/2;
		if (idx <= m) at->l = insert(at->l, idx, val, l, m);
		else at->r = insert(at->r, idx, val, m+1, r);
		return at->update(), at;
	}
	ll query(node* at, int a, int b, int l, int r) {
		if (!at or b < l or r < a) return 0;
		at->prop();
		if (a <= l and r <= b) return at->val;
		int m = (l+r)/2;
		return query(at->l, a, b, l, m) + query(at->r, a, b, m+1, r);
	}
	ll query(int c, int a, int b) { return query(seg[c], a, b, 0, n-1); }
	void update(node* at, int a, int b, int x, int l, int r) {
		if (!at or b < l or r < a) return;
		at->prop();
		if (a <= l and r <= b) {
			at->lazy += x;
			return void(at->prop());
		}
		int m = (l+r)/2;
		update(at->l, a, b, x, l, m), update(at->r, a, b, x, m+1, r);
		at->update();
	}
	void update(int c, int a, int b, int x) { update(seg[c], a, b, x, 0, n-1); }
	void paint(node*& from, node*& to, int a, int b, int l, int r) {
		if (to == from or !from or b < l or r < a) return;
		from->prop();
		if (to) to->prop();
		if (a <= l and r <= b) {
			if (!to) {
				to = from;
				from = NULL;
				return;
			}
			int m = (l+r)/2;
			paint(from->l, to->l, a, b, l, m), paint(from->r, to->r, a, b, m+1, r);
			to->update();
			delete from;
			from = NULL;
			return;
		}
		if (!to) to = new node();
		int m = (l+r)/2;
		paint(from->l, to->l, a, b, l, m), paint(from->r, to->r, a, b, m+1, r);
		from->update(), to->update();
	}
	void paint(int c1, int c2, int a, int b) { paint(seg[c1], seg[c2], a, b, 0, n-1); }
};

void solve(){

    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<pair<int, int>> x;
    vector<bool> changed(n, false);
    for (char c : s) {
        if (c == 'R') x.push_back({1, 0});
        else if (c == 'G') x.push_back({1, 1});
        else if (c == 'B') x.push_back({1, 2});
        else assert(false);
    }

    seg_color sg(x, 3);

    while(m--) {
        int l, r; cin >> l >> r;
        l--, r--;
        vector<pair<int, int>> ints;
        for (int i = l; i < = r;i++) {
            while (changed[i]) i++;
            int L = i;
            while (!changed[i]) i++;
            i--;
            ints.push_back({L, i});
        }
        for (auto [i, j] : ints) {
            sg.paint(0, 2, i, j);
            sg.paint(1, 0, i, j);
            sg.paint(2, 1, i, j);
        }
        int R = sg.query(0, 0, n-1);
        int G = sg.query(1, 0, n-1);
        int B = sg.query(2, 0, n-1);
        cout << R << " " << G << " " << B << endl;
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
