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
    string st; cin >> st;
    for(auto& x: st){
        if(x == 'H' || x == 'Q' || x == '9') { cout << "YES\n"; return; }
    }

    cout << "NO\n"; return;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
