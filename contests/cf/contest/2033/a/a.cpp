#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	bool k = 0; int x = 0, i = 1;
	while(abs(x) <= n){
		int units = 2*i-1;
		if(k) x += units;
		else x -= units;
		k = !k, i++;
	}
	if(!k) cout << "Kosuke" << endl;
	else cout << "Sakurako" << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
