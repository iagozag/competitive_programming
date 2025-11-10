#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<vector<int>> seg[4*MAX];
vector<vector<int>> v;

vector<vector<int>> upd_col(vector<int> col){
	vector<vector<int>> ans(3, vector<int>(3));
	ans[0][0] = (col[0] ? 0 : LINF);
	ans[1][1] = (col[1] ? 0 : LINF);
	ans[2][2] = (col[2] ? 0 : LINF);
	ans[0][1] = ans[1][0] = (!col[0] or !col[1] ? LINF : 1);
	ans[1][2] = ans[2][1] = (!col[1] or !col[2] ? LINF : 1);
	ans[0][2] = ans[2][0] = min(ans[0][1]+ans[1][2], LINF);

	return ans;
}

vector<vector<int>> combine(vector<vector<int>> a, vector<vector<int>> b){
	vector<vector<int>> c(3, vector<int>(3, LINF));

	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++)
		c[i][j] = min({c[i][j], LINF, a[i][k]+b[k][j]+1});
	
	return c;
}

vector<vector<int>> build(int p = 1, int l = 0, int r = n-1){
	if(l == r){
		vector<int> tmp = {v[0][l], v[1][l], v[2][l]};
		return seg[p] = upd_col(tmp);
	}

	int m = l+(r-l)/2;
	return seg[p] = combine(build(p*2, l, m), build(p*2+1, m+1, r));
}

vector<vector<int>> update(int idx, vector<int> col, int p = 1, int l = 0, int r = n-1){
	if(idx < l or idx > r) return seg[p];
	if(l == r) return seg[p] = upd_col(col);

	int m = l+(r-l)/2;
	return seg[p] = combine(update(idx, col, p*2, l, m), update(idx, col, p*2+1, m+1, r));
}

int query(){
	return (seg[1][0][2] >= LINF ? -1 : seg[1][0][2]);
}

void solve(){
	cin >> n;
	v = vector<vector<int>>(3, vector<int>(n));
	for(int i = 0; i < 3; i++) for(int j = 0; j < n; j++) {
		char c; cin >> c;
		v[i][j] = (c == '.');
	}
	
	build();

	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int r, c; cin >> r >> c; --r , --c;
		v[r][c] = !v[r][c];

		vector<int> tmp = {v[0][c], v[1][c], v[2][c]};
		update(c, tmp);

		cout << query() << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
