#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, q; cin >> n >> q;
	int l = 0, r = 1, ans = 0;
	for(int i = 0; i < q; i++){
		char h; int c; cin >> h >> c; --c;
		if(h == 'L'){
			int j = l, tot = 0; bool can = 1;
			while(j != c){
				if(j == r){ can = 0; break; }
				tot++, j = (j+1)%n;
			}
			if(can){ ans += tot, l = c; continue;}

			tot = 0, j = l;
			while(j != c){
				tot++, j = (j-1+n)%n;
			}
			ans += tot, l = c;
		} else{
			int j = r, tot = 0; bool can = 1;
			while(j != c){
				if(j == l){ can = 0; break; }
				tot++, j = (j+1)%n;
			}

			if(can){ ans += tot, r = c; continue;}

			tot = 0, j = r;
			while(j != c){
				tot++, j = (j-1+n)%n;
			}
			ans += tot, r = c;
		}
	}
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
