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

int m, n;
map<vi,int> mp;
vi ballons;

bool is_possible(int c){
    int b = 0;
    while(c > 0){
        for(auto& m: mp){
            b += m.first[1];
            c -= m.first[0] * m.first[1];

            if(c <= 0) break;
        }
        
    }
    
    return (b >= m);
}

void solve(){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        vi temp(3);
        for(int j = 0; j < 3; j++) cin >> temp[j];
        mp.insert({temp,i});
    }

    int l = 0, r = 1e6;
    while(l < r){
        int m = (l+r)/2;

        if(!is_possible(m)) l = m+1;
        else r = m;
    }

    cout << l << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
