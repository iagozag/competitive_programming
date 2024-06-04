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
    int n, k; cin >> n >> k;
    vector<char> even, odd;
    for(int i = 0; i < n; i++){
        char a; cin >> a;
        (i % 2 == 0) ? even.pb(a) : odd.pb(a);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    string str = "";
    for(size_t i = 0; i < even.size(); i++){
        str += even[i];
        if(i < odd.size()) str += odd[i];
    }
    
    if(k % 2 == 0) sort(all(str));

    cout << str << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
