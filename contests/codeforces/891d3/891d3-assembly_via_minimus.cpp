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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    map<int,int> mp; int len = (n*(n-1))/2;

    for(int i = 0; i < len; i++){
        int a; cin >> a; mp[a]++;
    }

    vi ans; int i = 0;
    for(auto x: mp){
        int goal = x.s;
        
        ans.pb(x.f);
        i++, goal -= n-i;

        while(goal > 0){
            ans.pb(x.f);
            i++, goal -= n-i;;
        }
    }
    while(ans.size() < n) ans.pb(1e9);

    for(auto &x: ans) cout << x << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
