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
	string s; cin >> s; int n = s.size();
	for(int i = 1; i < n; i++){
		int j = i;
		while(j > 0 and s[j] > '0' and s[j] > s[j-1]+1) s[j]--, swap(s[j], s[j-1]), j--;
		i = j;
	}
	cout << s << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
