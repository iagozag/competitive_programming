#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;

	string s; cin >> s; stack<int> s0, s1; ll ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '0') s0.push(i+1);
		else s1.push(i+1);
	}

	for(int i = n-1; i >= 0; i--){
		if(s[i] == '1'){
			if(s0.size()) ans += s0.top(), s0.pop(), s1.pop();
			else{
				int sz = s1.size()/2;
				while(sz--) s1.pop();
				while(!s1.empty()) ans += s1.top(), s1.pop();
			}
		} else if(s0.size() and s0.top() == i+1) ans += s0.top(), s0.pop();
	}

	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
