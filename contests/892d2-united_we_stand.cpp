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

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    vector<int> b;
    vector<int> c;
    int j;
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i-1]) b.pb(v[i-1]);
        else{
            b.pb(v[i-1]);
            j = i;
            break;
        }
    }

    while(j < v.size()){
        c.pb(v[j]);
        j++;
    }
   
    if(c.size() == 0 || b[0] == c[0]) cout << -1 << endl;
    else{
        cout << b.size() << " " << c.size() << endl;
        for(auto& e: b) cout << e << " ";
        cout << endl;
        for(auto& e: c) cout << e << " ";
        cout << endl;
    }
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
