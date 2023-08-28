#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n, m, d; cin >> n >> m >> d;

    vector<int> c;
    for(int i = 0; i < m; i++){
        int a; cin >> a; c.pb(a-1);
    }

    vector<int> ans(n);
    int position = -1, plat = 0, w = 0;
    while(m--){
        plat++;

        if(position+d >= n){
            for(int i = 1; i <= m; i++){
                ans[n-i] = plat;
                plat++;
            }
            position++;
            break;
        }

        position += d;
        if(position >= n){
            ans[n-1] = plat;
            position++;
            break;
        }

        ans[position] = plat;
        while(c[w]--){
            position++;
            ans[position] = plat;
        }

        w++;
    }
    
    position += d;
    (position >= n) ? cout << "YES\n" : cout << "NO\n";

    for(auto e: ans) cout << e << " ";
    cout << endl;

    exit(0);
}
