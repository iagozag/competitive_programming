#include <iostream>
using namespace std;

#define endl '\n'

void solve(){
	int n; cin >> n;
	int ans = 0, sum = 0;
	for(int i = 0; i < n; i++){ int x; cin >> x; ans ^= x, sum += x; }
	if(sum == n){
		cout << (n&1 ? "Brother" : "John") << endl;
		return;
	}
	cout << (ans == 0 ? "Brother" : "John") << endl;
}

int main(){
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


