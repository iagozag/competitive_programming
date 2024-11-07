#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, k; cin >> n >> k;

	if(k == n/2+1 or n == 1){ cout << 1 << endl << 1 << endl; return; }
	if(k == 1 or k == n){ cout << -1 << endl; return; }

	if(k%2 == 0){
		cout << 3 << endl;
		cout << 1 << " " << k << " " << k+1 << endl;
	} else{
		cout << 5 << endl;
		cout << "1 2 " << k << " " << k+1 << " " << k+2 << endl;
	}
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
