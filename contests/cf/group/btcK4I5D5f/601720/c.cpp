#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

bool valid(char c){
	return !(c >= 'a' and c <= 'z') and !(c >= 'A' and c <= 'Z');
}

void solve(){
	string s;
	while(getline(cin, s)){
		for(int i = 0; i < (int)s.size(); i++){
			int m = s.size();
			char x = s[i];
			if(x == 'C' and 
			   i and s[i-1] != ' ' and
			   (i == m-1 or valid(s[i+1]))) cout << "-se";
			else cout << x;
		}
		cout << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
