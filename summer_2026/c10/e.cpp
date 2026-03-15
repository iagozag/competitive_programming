#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 2e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

int n, M;
int mod[40];

void combine(int* c, int* a, int* b){
	for(int i = 0; i < M; i++) c[i] = a[i]+b[i];

	for(int i = 0; i < M; i++) for(int j = 0; j < M; j++)
		c[mod[i+j]] += a[i]*b[j]%MOD;

	for(int i = 0; i < M; i++) c[i] %= MOD;
}

int seg[2 * MAX][20];

void build() {
	for (int i = n - 1; i; i--) combine(seg[i], seg[2*i], seg[2*i+1]);
}

void query(int* ret, int a, int b) {
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		int tmp[20]; for(int j = 0; j < M; j++) tmp[j] = ret[j];
		if (a % 2 == 1) combine(ret, tmp, seg[a]);

		for(int j = 0; j < M; j++) tmp[j] = ret[j];
		if (b % 2 == 0) combine(ret, tmp, seg[b]);
	}
}

void solve(){
	cin >> n >> M;
	vector<int> v(n); for(auto& x: v) cin >> x, x %= M;

	for(int i = 0; i < 40; i++) mod[i] = i%M;

	memset(seg, 0, sizeof seg);
	for(int i = 0; i < n; i++){ seg[i+n][v[i]] = 1; }

	build();

	int q; cin >> q;
	for(int qq = 0; qq < q; qq++){
		int a, b; cin >> a >> b; --a, --b;

		int qnt[M]; memset(qnt, 0, sizeof qnt);
		query(qnt, a, b);

		 cout << qnt[0]+1 << endl;
	}
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;


	while(ttt--) solve();

	exit(0);
}
