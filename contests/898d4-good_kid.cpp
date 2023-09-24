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
    int n; cin >> n;
    vi v(n);
    int mini = 10, idx;
    for(int i = 0; i < n; i++) {
        cin >> v[i]; if(mini > v[i]) mini = v[i], idx = i;
    }

    ll mult = 1;
    for(int i = 0; i < n; i++){
        if(i==idx) mult*=v[i]+1;
        else mult*=v[i];
    }
    
    cout << mult << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
