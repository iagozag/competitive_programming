#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void bob(){ cout << "Bob" << endl; }
void alice(){ cout << "Bob" << endl; }

void solve(){
	int n, k; cin >> n >> k;

	while(n <= k){
		if(n == k) return bob();

		if(k&1) k /= 2;
		else k = k/2-1;
	}

	cout << "Alice" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

