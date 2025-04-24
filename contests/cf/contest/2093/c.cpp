#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void yes(){
	cout << "YES" << endl;
}

void no(){
	cout << "NO" << endl;
}

void solve(){
	int n, k; cin >> n >> k;

	if(n == 1 and k == 2) return yes();
	
	int prime = (n != 1);
	for(int i = 2; i <= sqrt(n); i++) if(n%i == 0) prime = 0;

	if(prime and k == 1) return yes();
	return no();
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
