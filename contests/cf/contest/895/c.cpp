#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int basis[20], sz = 0;

void insert_basis(int n){
	for(int i = 0; i < 20; i++){
		if(!(n&(1<<i))) continue;

		if(!basis[i] and n){
			basis[i] = n;
			sz++;
			return;
		}

		n ^= basis[i];
	}
}

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];

	map<int, int> mp; int id = 0;
	for(int i = 2; i < 70; i++){
		bool can = 1;
		for(int j = 2; j*j <= i; j++) if(i%j==0) can = 0;
		if(can) mp[i] = id++;
	}

	for(int i = 0; i < n; i++){
		int num = 0, k = v[i];

		for(auto [p, y]: mp) while(k%p == 0){
			k /= p, num ^= (1<<y);
		}

		insert_basis(num);
	}

	int ans = 1;
	for(int i = 0; i < n-sz; i++) ans = ans*2%MOD;
	cout << (ans-1+MOD)%MOD << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
