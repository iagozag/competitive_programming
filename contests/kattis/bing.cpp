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
	vector<node*> child;
	int qnt;

	node(){ child = vector<node*>(26); qnt = 0; }
};

int insert(node* nd, const char* s){
	if(*s){
		if(!nd->child[*s-'a']) nd->child[*s-'a'] = new node();

		nd->child[*s-'a']->qnt++;
		return insert(nd->child[*s-'a'], s+1);
	}
	return nd->qnt-1;
}

void solve(){
	int n; cin >> n;
	node* root = new node();
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		cout << insert(root, s.c_str()) << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
