#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int query(int l, int r){
	cout << "? " << l << " " << r << endl;
	int x; cin >> x;
	return x;
}

void solve(){
	int n; cin >> n; string s = "";
	for(int i = 0; i < n; i++) s += "2";

	int prev = 0;
	for(int i = 0; i < n-1; i++){
		int q = query(i+1, i+2);
		if(q == 1){
			s[i] = '0', s[i+1] = '1', i++;
			if(i == 1 or prev == i-1){ prev = i+1; continue; }

			int cnt = query(prev+1, i+1)-1, j = i-2;
			while(cnt--) s[j--] = '0';
			for(int l = prev; l <= j; l++) s[l] = '1';
			prev = i+1;
		}
	}

	if(s[n-1] == '2' and prev != 0){
		int q = query(prev-1, n)-1;
		for(int i = prev; i < n; i++) s[i] = (i < prev+q ? '1' : '0');
	}
	
	for(int i = 0; i < n; i++) if(s[i] == '2'){ cout << "! IMPOSSIBLE" << endl; return; }
	cout << "! " << s << endl;
}

int main(){
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
