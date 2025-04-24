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
	vector<vector<int>> v(n, vector<int>(n));
	vector<tuple<int, int>> q;
	for(int i = n-1; i >= 0; i--){
		q.emplace_back(1, i+1);
		q.emplace_back(2, i+1);
		for(int j = 0; j < n; j++) v[i][j] = j+1, v[j][i] = j+1;
	}

	int sum = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) sum += v[i][j];

	cout << sum << ' ' << q.size() << endl;
	for(auto [a, b]: q){
		cout << a << ' ' << b << ' ';
		for(int j = 1; j <= n; j++) cout << j << ' ';
		cout << endl;
	}
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
