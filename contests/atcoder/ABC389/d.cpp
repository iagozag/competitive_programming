#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<pair<long double, long double>> moves = {{-0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5}, {0.5, -0.5}};

bool good(int i, int m, int r){
	vector<pair<long double, long double>> coord(4);
	for(int j = 0; j < 4; j++) coord[j] = {(long double)i+moves[j].first, (long double)m+moves[j].second};
	for(auto [a, b]: coord) if(sqrt((a)*(a)+(b)*(b)) > (long double)r) return false;
	return true;
}

void solve(){
	int r; cin >> r;
	int ans = 0;
	for(int i = 1; i < r; i++){
		int l = 0, ri = r, can = 0;
		while(l <= ri){
			int m = l+(ri-l)/2;
			if(good(i, m, r)) can = m, l = m+1;
			else ri = m-1;
		}
		ans += can;
	}

	cout << (ans+r-1)*4+1 << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
