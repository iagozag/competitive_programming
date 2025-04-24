#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

set<int> st;

void solve(){
	int n; cin >> n;
	if(st.count(n)) cout << "YES" << endl;
	else{
		int l = 2, r = 1e9, k = 0;
		while(l <= r){
			int m = l+(r-l)/2;
			if(1+m+m*m > n) r = m-1;
			else if(1+m+m*m < n) l = m+1;
			else{ k = m; break; }
		}

		cout << (k ? "YES" : "NO") << endl;
	}
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	for(int i = 2; i <= 1e6; i++){
		__int128 sum = 1+i+i*i, pot = i*i*i;
		st.insert(1+i+i*i);
		while(sum+pot <= 1e18) sum += pot, pot *= i, st.insert((int)sum);
	}

    while(ttt--) solve();

    exit(0);
}
