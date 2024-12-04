#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int k; cin >> k; map<int, int> st;
	vector<int> v(k); for(auto& x: v) cin >> x, st[x]++;
	k -= 2;
	for(auto x: v){
		if(k%x == 0 and ((k/x != x and st[k/x] >= 1) or (k/x == x and st[k/x] > 1))){ cout << x << " " << k/x << endl; return; }
	}
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
