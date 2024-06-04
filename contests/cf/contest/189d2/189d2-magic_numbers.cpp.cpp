#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
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
    string n; cin >> n;

    vector<string> mn = {"144", "14", "1"};
    while(n.size() > 0){
        if(n[0] == mn[0][0] && n[1] == mn[0][1] && n[2] == mn[0][2]){
            n.erase(0,3); continue;
        }
        if(n[0] == mn[1][0] && n[1] == mn[1][1]){
            n.erase(0,2); continue;
        }
        if(n[0] == mn[2][0]){
            n.erase(0,1); continue;
        }

        cout << "NO\n";
        return;
    }

    cout << "YES\n"; return;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
