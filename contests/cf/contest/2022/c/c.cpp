#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<vector<int>> memo, v;

int dp(int i, int c){
	if(i > n) return -INF;

	int& p = memo[i][c];
	if(p != -1) return p;

	if(i == n) return p = (c == 0 ? 0 : -INF);

	int ma = 0;
	if(c == 0){
		if(i+1 < n) ma = max(ma, (v[0][i]+v[0][i+1]+v[1][i])/2+dp(i+1, 1));
		if(i+1 < n) ma = max(ma, (v[0][i]+v[1][i]+v[1][i+1])/2+dp(i+1, 2));
		if(i+2 < n) ma = max(ma, (v[0][i]+v[0][i+1]+v[0][i+2])/2+(v[1][i]+v[1][i+1]+v[1][i+2])/2+dp(i+3, 0));
	} else if(c == 1){
		if(i+1 < n) ma = max(ma, (v[1][i]+v[0][i+1]+v[1][i+1])/2+dp(i+2, 0));
		if(i+3 < n) ma = max(ma, (v[1][i]+v[1][i+1]+v[1][i+2])/2+(v[0][i+1]+v[0][i+2]+v[0][i+3])/2+dp(i+3, 1));
	} else{
		if(i+1 < n) ma = max(ma, (v[0][i]+v[1][i+1]+v[0][i+1])/2+dp(i+2, 0));
		if(i+3 < n) ma = max(ma, (v[0][i]+v[0][i+1]+v[0][i+2])/2+(v[1][i+1]+v[1][i+2]+v[1][i+3])/2+dp(i+3, 2));
	}
	return p = ma;
}

void solve(){
	cin >> n;
	v = vector<vector<int>>(2, vector<int>(n));
	for(int i = 0; i < 2; i++){
		string s; cin >> s;
		for(int j = 0; j < n; j++) if(s[j] == 'A') v[i][j] = 1;
	}

	memo = vector<vector<int>>(n+1, vector<int>(3, -1));
	cout << dp(0, 0) << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
