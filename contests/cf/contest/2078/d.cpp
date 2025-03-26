#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(4));
	for(int i = 0; i < n; i++){
		char c; cin >> c; v[i][0] = (c == '+');
		cin >> v[i][1] >> c; v[i][2] = (c == '+');
		cin >> v[i][3];
	}

	vector<int> great(n+1);
	for(int i = n-1; i >= 0; i--){
		great[i] = great[i+1];
		if(!v[i][0] and v[i][2]) great[i] = 0;
		else if(v[i][0] and !v[i][2]) great[i] = 1;
		else if(!v[i][0] and !v[i][2]){
			if(v[i][1] != v[i][3]) great[i] = (v[i][1] < v[i][3]);
		}
	}

	vector<int> a = {1, 1};
	for(int i = 0; i < n; i++)
		a[great[i+1]] += (v[i][0] ? v[i][1] : a[0]*(v[i][1]-1)) + (v[i][2] ? v[i][3] : a[1]*(v[i][3]-1));

	cout << a[0]+a[1] << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
