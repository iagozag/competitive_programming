#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

char invert(char c){
	if(c >= 97) return (char)(c-32);
	return (char)(c+32);
}

void solve(){
	string s; cin >> s; int n = s.size();
	int Q; cin >> Q;
	for(int i = 0; i < Q; i++){
		ll k; cin >> k; char c = s[(k-1)%n];
		k = (k-1)/n;
		while(k >= 1){
		 	for(int j = 62; j >= 0; j--) if(k >= (1LL<<j)) k -= (1LL<<j), c = invert(c);
		}

		cout << c << " ";
	}
	cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
