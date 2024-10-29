#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> last;

void solve(){
	int n, q; cin >> n >> q; int k = 0;
	map<int, int> mp; vector<int> v(n);
	for(int i = 0; i < n; i++){
		int a; cin >> a; if(!mp.count(a)) mp[a] = k++;
		v[i] = mp[a];
	}

}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
