#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int query(string& s){
    cout << "? " << s << endl;
    int q; cin >> q;
    return q;
}

void solve(){
    int n; cin >> n;
    string ans = string(n, '-');
    string zz = string(n, 'z');
    int qntz = query(zz);

    for(int i = 0; i < 25; i++){
        string s = string(n, (char)(i+'a'));
        int q = query(s);

        int cnt = 0; s = string(n, 'z');
        for(int j = 0; j < n and cnt < q; j++){
            s[j] = (char)(i+'a');
            int qq = query(s)-qntz;
            if(qq == 1) ans[j] = s[j], cnt++;
            s[j] = 'z';
        }
    }

    for(int i = 0; i < n; i++) if(ans[i] == '-') ans[i] = 'z';
    cout << "! " << ans << endl;
	exit(0);
}

int32_t main(){
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

