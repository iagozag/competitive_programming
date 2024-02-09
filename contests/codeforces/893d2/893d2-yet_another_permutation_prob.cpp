#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vi ans;
    set<int> rep;

    if(n % 2 == 1){
        ans.pb(n); rep.insert(n);
        n--;
    }

    while(n > 0){
        int div = n;
        while(div%2 == 0 && !rep.count(div)){
            ans.pb(div); rep.insert(div);
            div /= 2;
        }
        if(!rep.count(div)){
            ans.pb(div); rep.insert(div);
        }

        n--;
    }
 
    for(auto& x: ans) cout << x << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
