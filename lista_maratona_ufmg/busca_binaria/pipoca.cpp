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

int n, c, t;
vector<int> v;

bool possible(ll m){
    int comp = 1;
    ll rest = t*m;
    for(int i = 0; i < n; i++){
        if(rest >= v.at(i)) rest -= v.at(i);
        else{
            comp++;
            rest = t*m;
            i--;
        } 

        if(comp > c) return false;
    }

    return true;
}

int main(){ _
    cin >> n >> c >> t;
    
    for(int i = 0; i < n; i++){
        int a; cin >> a; v.pb(a);
    }

    int l = 0, r = 1e9+1;
    while(l < r){
        int m = (l+r)/2;
        if(!possible(m)) l = m+1;
        else r = m;
    }

    cout << l << endl;
    exit(0);
}
