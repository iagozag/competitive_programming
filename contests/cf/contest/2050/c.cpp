#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	string s; cin >> s;
	int sum = 0, qnt2 = 0, qnt3 = 0;
	for(auto& x: s){
		if(x == '2') qnt2++;
		if(x == '3') qnt3++;
		sum += (x-'0');
	}

	sum %= 9;

	for(int i = 0; i <= qnt2 and sum; i++) for(int j = 0; j <= qnt3 and sum; j++){
		if((sum+i*2+j*6)%9 == 0) sum = 0;
	}
	
	if(!sum) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
