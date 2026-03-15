#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

struct node{
	node *left, *right;
	int sum, lazy;

	node(){ left = right = nullptr, sum = 0, lazy = 0; }
};

void prop(node* p, int l, int r){
	if(l > r) return;

	if(!p->left) p->left = new node();
	if(!p->right) p->right = new node();

	if(p->lazy){
		p->sum = r-l+1;
		p->left->lazy = p->lazy;
		p->right->lazy = p->lazy;
		p->lazy = 0;
	}
}

void update(int a, int b, node* p, int l, int r){
	prop(p, l, r);
	if(a > r or b < l) return;
	if(a <= l and r <= b){
		p->lazy = 1;
		return;
	}

	int m = l+(r-l)/2;
	update(a, b, p->left, l, m);
	update(a, b, p->right, m+1, r);
	p->sum = p->left->sum+p->right->sum;
}


int query(int a, int b, node* p, int l, int r){
	prop(p, l, r);
	if(a > r or b < l) return 0;
	if(a <= l and r <= b) return p->sum;

	int m = l+(r-l)/2;
	return query(a, b, p->left, l, m) + query(a, b, p->right, m+1, r);
}

void solve(){
	int n, q; cin >> n >> q;

	node* root = new node();
	for(int i = 0; i < q; i++){
		int l, r; cin >> l >> r; --l, --r;
		update(l, r, root, 0, n-1);
		cout << n-query(0, n-1, root, 0, n-1) << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
