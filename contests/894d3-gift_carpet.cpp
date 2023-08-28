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
    int n, m; cin >> n >> m;
    vector<vector<char>> v;
    for(int i = 0; i < n; i++){
        vector<char> temp(m);
        for(int j = 0; j < m; j++) cin >> temp[j];
        v.pb(temp);
    }

    vector<char> letter = {'v', 'i', 'k', 'a'};
    int k = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(v[j][i] == letter[k]){
                k++;
                break; 
            }
        }
    }

    (k == 4) ? cout << "YES" : cout << "NO";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
