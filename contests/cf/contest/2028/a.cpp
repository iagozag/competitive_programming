#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, a, b; cin >> n >> a >> b;
	int x = 0, y = 0;
	string s; cin >> s;
	map<char, pair<int, int>> mp;
	mp['N'] = {0, 1}, mp['E'] = {1, 0}, mp['W'] = {-1, 0}, mp['S'] = {0, -1};

	for(int i = 0; i < 1000; i++){
		for(auto c: s){
			auto [nx, ny] = mp[c];
			x += nx, y += ny;
			if(x == a and y == b){ cout << "YES" << endl; return; }
		}
	}
	cout << "NO" << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
