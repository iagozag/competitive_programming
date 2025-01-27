#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int N = 200, MOD = 1e9+7;

int mat[200][200];
int pref[200][200];
int np[200][200];

int n, k;

void create_pref(){
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		pref[i][j] = (i ? pref[i-1][j] : 0) + (j ? pref[i][j-1] : 0) - (i and j ? pref[i-1][j-1] : 0) + np[i][j];
	}
}

int get_sum(int a, int b, int c, int d){
	return pref[c][d] - (a ? pref[a-1][d] : 0) - (b ? pref[c][b-1] : 0) + (a and b ? pref[a-1][b-1] : 0);
}

void calc(){
	int ans = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) ans += (mat[i][j] == k);
	cout << ans << endl;
}

void solve(){
	cin >> n >> k;
	memset(mat, 0, sizeof mat);
	memset(pref, 0, sizeof pref);

	for(int i = 0; i < n; i++){
		int a, b, c, d; cin >> a >> b >> c >> d; --a, --b, c -= 2, d -= 2;
		for(int l = a; l <= c; l++) for(int j = b; j <= d; j++) mat[l][j]++;
	}

	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		if(mat[i][j] == k) np[i][j] = -1;
		else if(mat[i][j] == k-1) np[i][j] = 1;
		else np[i][j] = 0;
	}
	
	create_pref();

	int a = -1, b = -1, c = -1, d = -1, ma = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		for(int l = 0; l < i; l++) for(int r = 0; r < j; r++){
			if(get_sum(l, r, i, j) > ma) ma = get_sum(l, r, i, j), a = l, b = r, c = i, d = j;
		}
	}

	if(a == -1) return calc();

	for(int i = a; i <= c; i++) for(int j = b; j <= d; j++) mat[i][j]++;

	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		if(mat[i][j] == k) np[i][j] = -1;
		else if(mat[i][j] == k-1) np[i][j] = 1;
		else np[i][j] = 0;
	}

	create_pref();

	a = -1, b = -1, c = -1, d = -1, ma = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		for(int l = 0; l < i; l++) for(int r = 0; r < j; r++){
			if(get_sum(l, r, i, j) > ma) ma = get_sum(l, r, i, j), a = l, b = r, c = i, d = j;
		}
	}

	for(int i = a; i <= c; i++) for(int j = b; j <= d; j++) mat[i][j]++;

	return calc();
}

int32_t main(){ _

	if (fopen("paintbarn.in", "r")) {
		freopen("paintbarn.in", "r", stdin);
		freopen("paintbarn.out", "w", stdout);
	}

    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
