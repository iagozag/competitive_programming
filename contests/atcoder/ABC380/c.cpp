#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, k; cin >> n >> k;
	string s; cin >> s; int b = 0, prev = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			b++;
			if(b == k){
				while(s[i] == '1') swap(s[prev++], s[i++]);
				break;
			} else{
				while(s[i+1] == '1') i++;
				prev = i+1;
			}
		}
	}
	cout << s << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
