#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

bool verify(int n){
	while(n){
		if(n%10 == 7) return true;
		n /= 10;
	}
	return false;
}

void solve(){
	int n; cin >> n;
	int res = 7;

	for(int i = 6; i >= 0; i--) for(int j = 0; j <= 999999999; j = j*10+9) if(verify(n+j*i)) res = i;

	cout << res << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
