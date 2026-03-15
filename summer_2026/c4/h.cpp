#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
	int n; cin >> n;
	for (int i = 0; i < (1<<n); i++){
		int num = i^(i>>1);
		for(int j = 0; j < n; j++) cout << ((num>>j)&1);
		cout << endl;
	}
	
}

int32_t main(){
	int ttt = 1; // cin >> ttt;
	while(ttt--) solve();

	exit(0);
}

